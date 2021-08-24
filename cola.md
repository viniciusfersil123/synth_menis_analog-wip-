⚠️IMPORTANTE⚠️<br>

Estas mudanças foram aplicadas apenas no layout acadêmico, portanto estão circunscritas somente pela pasta do referido layout.

# Mudanças implementadas
* Implementação de função de conversão de data do padrão recebio pelo JSON para o atual formato do Nexo, visando renderização de metadados 
* Transporte da estrutura do componente app do layout acadêmico do código do bitbucket para componente do Next (Componentes legados ainda estão comentados para futura implementação)
* Refatora classes dos elementos, retirando a referência ao "styles" do repo do bitbucket, assim, mesmo que ainda não funcional, mantemos um bom guia semântico de como implementar styled-components mantendo ao máximo a taxonomia do repo do bitbucket

🌈 Lembrando que é um WIP, portanto, essa (e provavelmente muitas das próximas PRs que farei) corresponde apenas a um babyzinho-step desta migração, não é uma decisão definitiva, vamos refatorando a medida que novas necessidades do processo de migração se impõem 
