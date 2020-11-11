#!/usr/bin/bash

echo $(dirname "$0")

URL=smtps://smtp.laposte.net:465
USER=jean.bnb@laposte.net
PASSWORD=lMzzPbCOYq4G7MyEXHqK
MAIL_FROM=jean.bnb@laposte.net
MAIL_RCPT=$USER
MAIL_FILE=mail.ex1.txt


CMD="curl \
  --verbose \
  --ssl-reqd \
  --url ${URL} \
  --user ${USER}:${PASSWORD} \
  --mail-from ${MAIL_FROM} \
  --mail-rcpt ${MAIL_RCPT} \
  --upload-file ${MAIL_FILE} \
  --insecure"

echo $CMD

$CMD