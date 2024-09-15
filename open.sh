#!/bin/bash
echo "Abrindo portas..."
nc -vnlp 80&
sleep 2
nc -vnlp 443&
sleep 2
nc -vnlp 53&
