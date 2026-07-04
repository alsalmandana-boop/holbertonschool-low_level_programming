FROM alpine

COPY message.txt /message.txt

RUN apk add --no-cache curl wget

CMD ["cat", "/message.txt"]
