#!/bin/bash
echo "Testando portas..."
nc -vn 172.20.1.73 80&
sleep 2
nc -vn 172.20.1.73 443&
sleep 2
nc -vn 172.20.1.73 53&
