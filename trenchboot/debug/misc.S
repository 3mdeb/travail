/* Use the TXT error register to show a value in sl_stub.S */
	movl	%esi, (TXT_PRIV_CONFIG_REGS_BASE + TXTCR_ERRORCODE)
	movl	(TXT_PRIV_CONFIG_REGS_BASE + TXTCR_E2STS), %eax
	movl	$1, (TXT_PRIV_CONFIG_REGS_BASE + TXTCR_CMD_UNLOCK_MEM_CONFIG)
	movl	(TXT_PRIV_CONFIG_REGS_BASE + TXTCR_E2STS), %eax
	movl	$1, (TXT_PRIV_CONFIG_REGS_BASE + TXTCR_CMD_RESET)
1:
	pause
	jmp 	1b

/* 64b */
	movq	%cr0, %rax
	movq	%rax, (TXT_PRIV_CONFIG_REGS_BASE + TXTCR_ERRORCODE)
	movq	(TXT_PRIV_CONFIG_REGS_BASE + TXTCR_E2STS), %rax
	movq	$0x1, %rcx
	movq	%rax, (TXT_PRIV_CONFIG_REGS_BASE + TXTCR_CMD_UNLOCK_MEM_CONFIG)
	movq	(TXT_PRIV_CONFIG_REGS_BASE + TXTCR_E2STS), %rax
	movq	%rax, (TXT_PRIV_CONFIG_REGS_BASE + TXTCR_CMD_RESET)
1:
	pause
	jmp 	1b

/* MTRR stuff */
	/* Disable all MTRRs and set cache default to UC */
	pushq	%rcx
	pushq	%rdx
	xorq	%rax, %rax
	xorq	%rdx, %rdx
	movq	$MSR_MTRRdefType, %rcx
	wrmsr
	popq	%rdx
	popq	%rcx

	/* Enable MTRRs and set cache default to WB */
	pushq	%rcx
	pushq	%rdx
	movq	$0x806, %rax
	xorq	%rdx, %rdx
	movq	$MSR_MTRRdefType, %rcx
	wrmsr
	popq	%rdx
	popq	%rcx
