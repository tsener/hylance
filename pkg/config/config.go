package config

import (
	"gopkg.in/yaml.v2"
	"io/ioutil"
)

type Config struct {
	Hitch   HitchConfig   `yaml:"hitch"`
	Balance BalanceConfig `yaml:"balance"`
}

type HitchConfig struct {
	Frontend string `yaml:"frontend"`
	PemFile  string `yaml:"pemFile"`
	Backend  string `yaml:"backend"`
	ClientCA string `yaml:"clientCA"`
}

type BalanceConfig struct {
	Listen   string   `yaml:"listen"`
	Backends []string `yaml:"backends"`
}

func Load(path string) (*Config, error) {
	data, err := ioutil.ReadFile(path)
	if err != nil {
		return nil, err
	}
	var c Config
	if err := yaml.Unmarshal(data, &c); err != nil {
		return nil, err
	}
	return &c, nil
}
