# Multi-stage build adding Balance to the official Hitch image

# Stage 1: build Balance
FROM debian:stable-slim AS balance-build
RUN apt-get update && apt-get install -y build-essential make
WORKDIR /src
COPY tcp/ ./tcp/
RUN make -C tcp && strip tcp/balance

# Stage 2: combine with Hitch and Python service
FROM hitch:1.8
RUN apt-get update && apt-get install -y python3 python3-yaml python3-bottle
COPY --from=balance-build /src/tcp/balance /usr/local/bin/balance
COPY cmd/service/main.py /usr/local/bin/hylance-service.py
COPY docker/start-hylance.sh /usr/local/bin/start-hylance.sh
RUN chmod +x /usr/local/bin/start-hylance.sh

CMD ["/usr/local/bin/start-hylance.sh"]
