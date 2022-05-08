#! /bin/bash

mosquitto_pub -h broker.emqx.io -t P203-UNO -m $1
