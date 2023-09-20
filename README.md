# PetC
Projeto em C desenvolvido ao longo da matéria DCT1106.

# Módulos e funcionalidades
```O projeto irá emular duas funcionalidades principais distintas no mesmo software, uma clinica veterinária junto com um petshop. O projeto contará com versões de cliente e versões de admin.```
## Módulo base:
- Autenticação para clientes e funcionários 
- Menu de escolha entre módulo de Petshop e Módulo veterinário (Menu principal)
- Cadastro de cliente 
- Cadastro de funcionários **(Disponível para Admins)**
### Telas:
- Menu principal{
  - Login ou cadastrar-se
  - Veterinário
  - Petshop
  - Cadastrar funcionário (**Aparecerá somente para funcionários logados**)
  - Sobre o projeto
  - Sair
    
}    
- Login ou cadastro{
  - Logar
  - Cadastrar-se
    
} 
- Login{
  - Campo de usuário
  - Campo de senha
  - Botão de logar
    
}
- Cadastro{
  - Nome completo (Obrigatório)
  - CPF (Obrigatório)
  - Telefone (Opcional)
  - Email (Obrigatório)
  - Senha (Obrigatório)
    
  **Haverá validação para saber se o usuário já é cadastrado (Pesquisa por cpf)**
  
}
- Sobre{
  - Infos sobre o projeto

}
## Módulo Veterinária
- Neste e nos demais módulos, haverão dois modos: O de Usuário e o de Admin. Os Admins terão todas as mesmas funcionalidades que clientes, porém terão funcionalidades extras.
- Marcar consultas com veterinário
- Verificar minhas consultas marcadas
  - Desmarcar consulta
  - Editar consulta
    - Essas duas opções funcionarão da seguinte forma: Quando o cliente fizer uma edição, uma notificação será enviada para o módulo de funcionários, que poderá aprovar ou negar.
- Verificar consultas marcadas **(Somente para funcionários)**
  - Editar consulta
  - Desmarcar consulta
  - Aprovar solicitação de mesmarcar e editar consulta
**Sub-Módulo: Marcar procedimentos estéticos (Tosa, banho, etc), onde haverá uma tabela de procedimentos disponíveis e as mesmas funcionalidades das consultas normais**


   
