package config

import (
	"os"
	"testing"
)

func TestLoad(t *testing.T) {
	data := []byte(`
hitch:
  frontend: "[0.0.0.0]:443"
  pemFile: "/tmp/test.pem"
  backend: "127.0.0.1:8080"
  clientCA: "/tmp/ca.pem"
balance:
  listen: "0.0.0.0 8080"
  backends:
    - "10.0.0.1:80"
    - "10.0.0.2:80"
`)
	f, err := os.CreateTemp("", "cfg*.yaml")
	if err != nil {
		t.Fatal(err)
	}
	defer os.Remove(f.Name())
	if _, err := f.Write(data); err != nil {
		t.Fatal(err)
	}
	f.Close()

	cfg, err := Load(f.Name())
	if err != nil {
		t.Fatalf("Load returned error: %v", err)
	}

	if cfg.Hitch.Frontend != "[0.0.0.0]:443" {
		t.Errorf("unexpected frontend %q", cfg.Hitch.Frontend)
	}
	if len(cfg.Balance.Backends) != 2 {
		t.Fatalf("expected two backends, got %d", len(cfg.Balance.Backends))
	}
}
