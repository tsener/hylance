package v1alpha1

// HylanceIngressSpec defines the desired state of HylanceIngress
// This is a minimal placeholder used by the controller.
type HylanceIngressSpec struct {
	TLSSecret string   `json:"tlsSecret"`
	Backends  []string `json:"backends"`
}
