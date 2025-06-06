package main

import (
	"context"
	"fmt"

	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
)

func main() {
	// Load in-cluster config or default kubeconfig
	cfg, err := clientcmd.BuildConfigFromFlags("", "")
	if err != nil {
		panic(err)
	}
	clientset, err := kubernetes.NewForConfig(cfg)
	if err != nil {
		panic(err)
	}

       // TODO: watch Ingress resources and generate YAML config for the Python service
	fmt.Println("Hylance controller started", clientset.RESTClient().APIVersion())
	<-context.Background().Done()
}
