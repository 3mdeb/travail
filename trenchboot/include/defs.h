#ifndef __DEFS_H__
#define __DEFS_H__

#define PAGE_SHIFT  12
#define PAGE_SIZE   (1 << PAGE_SHIFT)
#define PAGE_MASK   (~(PAGE_SIZE-1))

#define GIGABYTE    0x40000000

#ifdef __ASSEMBLY__
#define ENTRY(name)                             \
  .globl name;                                  \
  name:

#define ENTRY_ALIGN(name)                       \
  .globl name;                                  \
  .align 16,0x90;                               \
  name:
#endif

#define __packed        __attribute__ ((packed))
#define __maybe_unused  __attribute__ ((unused))

/* CRs */
#define CR0_PE  0x00000001 /* Protected mode Enable */
#define CR0_MP  0x00000002 /* "Math" (fpu) Present */
#define CR0_EM  0x00000004 /* EMulate FPU instructions. (trap ESC only) */
#define CR0_TS  0x00000008 /* Task Switched (if MP, trap ESC and WAIT) */
#define CR0_ET  0x00000010 /* Extension type */
#define CR0_PG  0x80000000 /* PaGing enable */
#define CR0_NE  0x00000020 /* Numeric Error enable (EX16 vs IRQ13) */
#define CR0_WP  0x00010000 /* Write Protect (honor page protect in all modes) */
#define CR0_AM  0x00040000 /* Alignment Mask (set to enable AC flag) */
#define CR0_NW  0x20000000 /* Not Write-through */
#define CR0_CD  0x40000000 /* Cache Disable */

#define CR4_VME 0x00000001 /* Virtual 8086 mode extensions */
#define CR4_PVI 0x00000002 /* Protected-mode virtual interrupts */
#define CR4_TSD 0x00000004 /* Time stamp disable */
#define CR4_DE  0x00000008 /* Debugging extensions */
#define CR4_PSE 0x00000010 /* Page size extensions */
#define CR4_PAE 0x00000020 /* Physical address extension */
#define CR4_MCE 0x00000040 /* Machine check enable */
#define CR4_PGE 0x00000080 /* Page global enable */
#define CR4_PCE 0x00000100 /* Performance monitoring counter enable */
#define CR4_FXSR 0x00000200/* Fast FPU save/restore used by OS */
#define CR4_XMM 0x00000400 /* enable SIMD/MMX2 to use except 16 */
#define CR4_VMXE 0x00002000/* enable VMX */
#define CR4_SMXE 0x00004000/* enable SMX */
#define CR4_PCIDE 0x00020000/* enable PCID */

/* MSRs */

#define MSR_EFER  0xc0000080
#define VM_CR_MSR 0xc0010114

/* EFER bits */
#define EFER_SCE 0  /* SYSCALL/SYSRET */
#define EFER_LME 8  /* Long Mode enable */
#define EFER_LMA 10 /* Long Mode Active (read-only) */
#define EFER_NXE 11  /* no execute */
#define EFER_SVME 12   /* SVM extensions enable */

/* VM CR MSR bits */
#define VM_CR_DPD 0
#define VM_CR_R_INIT 1
#define VM_CR_DIS_A20M 2
#define VM_CR_SVME_DISABLE 4

#endif /* __DEFS_H__ */
