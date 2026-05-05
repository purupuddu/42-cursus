# 3.22 is the penultimate minor. :latest is 3.23.x, this is 3.22.x
FROM alpine:3.22

# nginx install tutorial begin
RUN apk add openssl curl ca-certificates
RUN printf "%s%s%s%s\n" \
    "@nginx " \
    "https://nginx.org/packages/alpine/v" \
    `egrep -o '^[0-9]+\.[0-9]+' /etc/alpine-release` \
    "/main" \
    | tee -a /etc/apk/repositories
RUN curl -o /tmp/nginx_signing.rsa.pub https://nginx.org/keys/nginx_signing.rsa.pub
RUN mv /tmp/nginx_signing.rsa.pub /etc/apk/keys/
RUN apk add nginx@nginx
# nginx install tutorial end




