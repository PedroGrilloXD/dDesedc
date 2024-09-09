$ip = Read-Host "Digite o IP/Dominio"
$web = Invoke-WebRequest -uri "$ip" -Method Options
echo "O servidor roda:"
$web.headers.server
echo ""
echo "O servidor aceita os metodos:"
$web.headers.allow
echo ""
echo "Links encontrados"
$web2 = Invoke-WebRequest -uri "$ip"
$web2.links.href | Select-String http://
