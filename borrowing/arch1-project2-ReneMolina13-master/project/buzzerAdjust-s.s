	.arch msp430g2553
	.extern buzzerMax
	.extern buzzerIncrease
	.extern buzzerDecrease
	.extern buzzerZero

	.text
	.align 2
jt:
	.word BUZZER_MAX	;jt[0]
	.word BUZZER_INCREASE	;jt[1]
	.word BUZZER_DECREASE	;jt[2]
	.word BUZZER_ZERO	;jt[3]

	.global adjustBuzzer
adjustBuzzer:
	;; check if the index is outside of the bounds
	cmp #0, R12
	jl done
	cmp #4, R12
	jge done

	add R12, R12 		; 1 word = 2 bytes
	mov jt(R12), R0		; index into switch label
BUZZER_MAX:
	call #buzzerMax
BUZZER_INCREASE:
	call #buzzerIncrease
BUZZER_DECREASE:
	call #buzzerDecrease
BUZZER_ZERO:
	call #buzzerZero
done:	
	pop R0
