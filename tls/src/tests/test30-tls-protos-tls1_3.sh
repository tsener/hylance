#!/bin/sh
# Test TLS 1.3 availability.

. hitch_test.sh

if ! openssl s_client -help 2>&1 | grep -q -e "-tls1_3"
then
	skip "Missing TLSv1.3 support"
fi

# only TLSv1.3
cat >hitch.cfg <<EOF
backend = "[hitch-tls.org]:80"
frontend = "[*]:$LISTENPORT"
pem-file = "${CERTSDIR}/default.example.com"
tls-protos = TLSv1.3
EOF

start_hitch --config=hitch.cfg

# this will fail on platforms that have OpenSSL without TLS 1.3.
s_client -tls1_3
