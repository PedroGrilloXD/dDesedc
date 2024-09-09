param($ip)
if (!$ip){
echo "Desec Secutiry"
echo ".\portscan.ps1 192.168.0.1"
} else{ 
$topports = 21,22,3306,80,443
foreach ($porta in $topports){
if (Test-NetConnection $ip -port $porta -WarningAction SilentlyContinue -InformationLevel Quiet) 
	{echo "porta $porta aberta"}
		
}else {echo "porta $porta fechada"}
}
