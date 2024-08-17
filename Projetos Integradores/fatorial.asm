.data
	#dados da memória princial
	msg: .asciiz "Programa para fazer fatorial\n" #mensagem pro usu
	ver: .asciiz "Valor do fatorial\n"

	.text
	#dados de instruções do programa
	.globl main
	
main:	
	li $v0, 4       # li = load immediatly / $v0 é um registrador de retorno de função / 4 significa que ele vai carregar uma string
	la $a0, msg     #load address
	syscall         #printf do conteúdo que estiver no registrador $a0

	li $v0, 5       #li em $v0 seguido de 5 significa que o programa vai ler um inteiro
	syscall
	move $t0, $v0   #valor fornecido (aramzenado em$v0) foi passado para $t0
	
	li $t1, 1 	#fatorial para em 1
	li $t3, 1	#valor inicial para variável do resultado
	
while:
	beq $t0, $t1, exit #Se $t0 for igual a $t1, o programa deve rodar a partir de exit
	
	mul $t3, $t3, $t0 #multipkicação efetiva do fatorial
	subi $t0, $t0, 1 #decremento de $t0
	
	j while
exit:
	move $s0, $t3 	#passa resultado pra resgistrador salvo
	li $v0, 4       #ler string
	la $a0, ver
	syscall

	li $v0, 1         #ler inteiro
	move $a0, $s0     #move valor de $s0 para $a0
	syscall

	li $v0, 10     #Encerra o programa
	syscall