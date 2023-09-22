# PetC
Projeto em C desenvolvido ao longo da matéria DCT1106.

# Módulos e funcionalidades
```O projeto irá emular duas funcionalidades principais distintas no mesmo software, uma clinica veterinária junto com um petshop. O projeto contará com versões de cliente e versões de admin. Também contará com um módulo de admin simplificado```
## Módulo base:
- Autenticação para clientes e funcionários 
- Menu de escolha entre módulo de Petshop e Módulo veterinário (Menu principal)
- Cadastro de cliente 
### Telas:
- Menu principal{
  - Login ou cadastrar-se
  - Veterinário
  - Petshop
  - Módulo do Admin (**Aparecerá somenta para funcionários logados**)
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
  - Todos as funcionalidades desse móludo exigirão estar logados para acessar, menos o de procedimentos estéticos.
    
**Sub-Módulo: Marcar procedimentos estéticos (Tosa, banho, etc), onde haverá uma tabela de procedimentos disponíveis e as mesmas funcionalidades das consultas normais; Para pessoas não logadas, será possível somente ver o catalogo de procedimentos.**

### Telas:
- Menu Veterinário{
  - Consultas (**Acesso somente logado**)
  - Procedimentos estéticos
  - Voltar
  
 }
 
- Menu Consultas{
  - Agendar consulta
  - Minhas consultas
  - Tabela de Consultas (**Acesso para admin**)
  - Voltar

  }

- Menu Agendar Consulta{
  - Data da consulta
  - Hora da consulta
  - Sistema deverá checar se o horário está disponível
  - Sistema passará as informações do cliente que agendou automaticamente por seu login  
 }

 - Menu Minhas Consultas{
   - Exibir todas as consultas do usuário, marcado e desmarcado
   - Opção de pesquisar por data de consulta
   - Editar/Deletar consulta específica
  }

- Tabela de consultas{
  - Semelhante ao "Minhas consultas" porém com uma visão de administrador que contará com todas as consultas já registradas.
  - O admin poderá procurar por datas específicas  

- Menu Editar/Deletar consulta{
  - Opção de deletar ou editar
  - Se o usuário for admin, edita ou deleta direto
  - Se for cliente, envia solicitação para admin

}

- Menu Procedimentos{
  - Agendar procedimento
  - Minhas agendas
  - Tabela de procedimentos
  - Voltar
 
  }
  
- Menu Agendar procedimento{
  - Listagem com os procedimentos disponíveis
  - Data do procedimento
  - Hora do procedimento
  - Sistema deverá checar se o horário está disponível
  - Sistema passará as informações do cliente que agendou automaticamente por seu login  
  
 - Menu Meus procedimentos{
   - Exibir todos os procedimentos do usuário, marcado e desmarcado
   - Opção de pesquisar por data de procedimento
   - Editar/Deletar procedimento específico
  }

- Tabela de procedimentos{
  - Semelhante ao "Minhas consultas" porém com uma visão de administrador que contará com todas as consultas já registradas. (**Somente para admin**)
  - O admin poderá procurar por datas específicas
  - O admin também poderá cadastrar/editar/deletar procedimentos estéticos
  - Listagem com todos os procedimentos estéticos 

- Menu Editar/Deletar procedimento{
  - Opção de deletar ou editar
  - Se o usuário for admin, edita ou deleta direto
  - Se for cliente, envia solicitação para admin

}



   
