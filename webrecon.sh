#!/bin/bash
while true; do 
  echo "digite seu o dominio desejado:"
read dominio
  echo "digite a world list desejada:"
read world
  for palavra in $(cat $world);
do 
resposta=$(curl -s -H "User-Agent: Maquininha malvada" -o /dev/null -w "%{http_encode}" $dominio/$palavra/)
  if [$resposta == 200]
then
  echo "diretorio encontrado: $palavra"
fi 
  done

  echo "deseja realizar outra pesquisa? (s/n)"
  read continuar 

  if [[ ! "continuar" =~ ^[sS]$ ]]; then
  break 
fi
done
