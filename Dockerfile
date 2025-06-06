# Multi-stage build adding Balance to the official Hitch image

# Stage 1: build Balance
FROM debian:stable-slim AS balance-build
RUN apt-get update && apt-get install -y build-essential make
WORKDIR /src
COPY tcp/ ./tcp/
RUN make -C tcp && strip tcp/balance

# Stage 2: build the wrapper binary
FROM golang:1.18 AS wrapper-build
WORKDIR /src
COPY go.mod go.sum ./
RUN go mod download
COPY cmd/ ./cmd/
COPY pkg/ ./pkg/
RUN CGO_ENABLED=0 go build -o hylance-wrapper ./cmd/wrapper

# Stage 3: combine with Hitch
FROM hitch:1.8
COPY --from=balance-build /src/tcp/balance /usr/local/bin/balance
COPY --from=wrapper-build /src/hylance-wrapper /usr/local/bin/hylance-wrapper
COPY docker/start-hylance.sh /usr/local/bin/start-hylance.sh
RUN chmod +x /usr/local/bin/start-hylance.sh

CMD ["/usr/local/bin/start-hylance.sh"]
