!#/bin/bash
if ["$1" == ""]
then
  echo "DESEC SECURITY"
  echo "modo de uso: $0 Insira IP ou Dominio"
else
  ping -c 1 "$1"
  wget $1
  cat index.html | grep "href" | cut -d "/" -f 3 | grep "\." | cut -d '"' -f 1 | grep -v "<l" > lista.txt
fi 
for url do $(cat lista.txt);do host $url;
done
