package main

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"syscall"

	"github.com/example/hylance/pkg/config"
)

func writeHitchConf(cfg *config.HitchConfig) error {
	path := "/etc/hitch/hitch.conf"
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()

	fmt.Fprintf(f, "frontend = %s\n", cfg.Frontend)
	fmt.Fprintf(f, "backend = \"%s\"\n", cfg.Backend)
	fmt.Fprintf(f, "pem-file = %s\n", cfg.PemFile)
	if cfg.ClientCA != "" {
		fmt.Fprintf(f, "client-ca-file = %s\n", cfg.ClientCA)
		fmt.Fprintf(f, "verify-peer = on\n")
	}
	return nil
}

func writeBalanceConf(cfg *config.BalanceConfig) error {
	if cfg == nil || len(cfg.Backends) == 0 {
		return nil
	}
	path := "/etc/hylance/balance.conf"
	os.MkdirAll(filepath.Dir(path), 0755)
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()

	fmt.Fprintf(f, "%s", cfg.Listen)
	for _, b := range cfg.Backends {
		fmt.Fprintf(f, " %s", b)
	}
	fmt.Fprintln(f)
	return nil
}

func startBalance(cfg *config.BalanceConfig) (*exec.Cmd, error) {
	if cfg == nil || len(cfg.Backends) == 0 {
		return nil, nil
	}
	cmd := exec.Command("/usr/local/bin/balance", "/etc/hylance/balance.conf")
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	if err := cmd.Start(); err != nil {
		return nil, err
	}
	return cmd, nil
}

func runHitch() error {
	return syscall.Exec("/usr/sbin/hitch", []string{"hitch", "--config=/etc/hitch/hitch.conf"}, os.Environ())
}

func main() {
	path := os.Getenv("HYLANCE_CONFIG")
	if path == "" {
		path = "/etc/hylance/hylance.yaml"
	}

	cfg, err := config.Load(path)
	if err != nil {
		fmt.Fprintln(os.Stderr, "failed to load config:", err)
		os.Exit(1)
	}

	if err := writeHitchConf(&cfg.Hitch); err != nil {
		fmt.Fprintln(os.Stderr, "write hitch conf:", err)
		os.Exit(1)
	}
	if err := writeBalanceConf(&cfg.Balance); err != nil {
		fmt.Fprintln(os.Stderr, "write balance conf:", err)
		os.Exit(1)
	}

	if _, err := startBalance(&cfg.Balance); err != nil {
		fmt.Fprintln(os.Stderr, "start balance:", err)
		os.Exit(1)
	}

	if err := runHitch(); err != nil {
		fmt.Fprintln(os.Stderr, "run hitch:", err)
		os.Exit(1)
	}
}
