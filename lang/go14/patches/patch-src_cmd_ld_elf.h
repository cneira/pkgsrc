$NetBSD: patch-src_cmd_ld_elf.h,v 1.1 2016/02/21 14:32:24 bsiegert Exp $

--- src/cmd/ld/elf.h.orig	2015-09-23 04:37:36.000000000 +0000
+++ src/cmd/ld/elf.h
@@ -478,32 +478,47 @@ typedef struct {
  * Relocation types.
  */
 
-#define	R_X86_64_NONE	0	/* No relocation. */
-#define	R_X86_64_64	1	/* Add 64 bit symbol value. */
-#define	R_X86_64_PC32	2	/* PC-relative 32 bit signed sym value. */
-#define	R_X86_64_GOT32	3	/* PC-relative 32 bit GOT offset. */
-#define	R_X86_64_PLT32	4	/* PC-relative 32 bit PLT offset. */
-#define	R_X86_64_COPY	5	/* Copy data from shared object. */
-#define	R_X86_64_GLOB_DAT 6	/* Set GOT entry to data address. */
-#define	R_X86_64_JMP_SLOT 7	/* Set GOT entry to code address. */
-#define	R_X86_64_RELATIVE 8	/* Add load address of shared object. */
-#define	R_X86_64_GOTPCREL 9	/* Add 32 bit signed pcrel offset to GOT. */
-#define	R_X86_64_32	10	/* Add 32 bit zero extended symbol value */
-#define	R_X86_64_32S	11	/* Add 32 bit sign extended symbol value */
-#define	R_X86_64_16	12	/* Add 16 bit zero extended symbol value */
-#define	R_X86_64_PC16	13	/* Add 16 bit signed extended pc relative symbol value */
-#define	R_X86_64_8	14	/* Add 8 bit zero extended symbol value */
-#define	R_X86_64_PC8	15	/* Add 8 bit signed extended pc relative symbol value */
-#define	R_X86_64_DTPMOD64 16	/* ID of module containing symbol */
-#define	R_X86_64_DTPOFF64 17	/* Offset in TLS block */
-#define	R_X86_64_TPOFF64 18	/* Offset in static TLS block */
-#define	R_X86_64_TLSGD	19	/* PC relative offset to GD GOT entry */
-#define	R_X86_64_TLSLD	20	/* PC relative offset to LD GOT entry */
-#define	R_X86_64_DTPOFF32 21	/* Offset in TLS block */
-#define	R_X86_64_GOTTPOFF 22	/* PC relative offset to IE GOT entry */
-#define	R_X86_64_TPOFF32 23	/* Offset in static TLS block */
-
-#define	R_X86_64_COUNT	24	/* Count of defined relocation types. */
+#define	R_X86_64_NONE           0
+#define	R_X86_64_64             1
+#define	R_X86_64_PC32           2
+#define	R_X86_64_GOT32          3
+#define	R_X86_64_PLT32          4
+#define	R_X86_64_COPY           5
+#define	R_X86_64_GLOB_DAT       6
+#define	R_X86_64_JMP_SLOT       7
+#define	R_X86_64_RELATIVE       8
+#define	R_X86_64_GOTPCREL       9
+#define	R_X86_64_32             10
+#define	R_X86_64_32S            11
+#define	R_X86_64_16             12
+#define	R_X86_64_PC16           13
+#define	R_X86_64_8              14
+#define	R_X86_64_PC8            15
+#define	R_X86_64_DTPMOD64       16
+#define	R_X86_64_DTPOFF64       17
+#define	R_X86_64_TPOFF64        18
+#define	R_X86_64_TLSGD          19
+#define	R_X86_64_TLSLD          20
+#define	R_X86_64_DTPOFF32       21
+#define	R_X86_64_GOTTPOFF       22
+#define	R_X86_64_TPOFF32        23
+#define	R_X86_64_PC64           24
+#define	R_X86_64_GOTOFF64       25
+#define	R_X86_64_GOTPC32        26
+#define	R_X86_64_GOT64          27
+#define	R_X86_64_GOTPCREL64     28
+#define	R_X86_64_GOTPC64        29
+#define	R_X86_64_GOTPLT64       30
+#define	R_X86_64_PLTOFF64       31
+#define	R_X86_64_SIZE32         32
+#define	R_X86_64_SIZE64         33
+#define	R_X86_64_GOTPC32_TLSDEC 34
+#define	R_X86_64_TLSDESC_CALL   35
+#define	R_X86_64_TLSDESC        36
+#define	R_X86_64_IRELATIVE      37
+#define	R_X86_64_PC32_BND       40
+#define	R_X86_64_GOTPCRELX      41
+#define	R_X86_64_REX_GOTPCRELX  42
 
 
 #define	R_ALPHA_NONE		0	/* No reloc */
@@ -581,39 +596,42 @@ typedef struct {
 #define	R_ARM_COUNT		38	/* Count of defined relocation types. */
 
 
-#define	R_386_NONE	0	/* No relocation. */
-#define	R_386_32	1	/* Add symbol value. */
-#define	R_386_PC32	2	/* Add PC-relative symbol value. */
-#define	R_386_GOT32	3	/* Add PC-relative GOT offset. */
-#define	R_386_PLT32	4	/* Add PC-relative PLT offset. */
-#define	R_386_COPY	5	/* Copy data from shared object. */
-#define	R_386_GLOB_DAT	6	/* Set GOT entry to data address. */
-#define	R_386_JMP_SLOT	7	/* Set GOT entry to code address. */
-#define	R_386_RELATIVE	8	/* Add load address of shared object. */
-#define	R_386_GOTOFF	9	/* Add GOT-relative symbol address. */
-#define	R_386_GOTPC	10	/* Add PC-relative GOT table address. */
-#define	R_386_TLS_TPOFF	14	/* Negative offset in static TLS block */
-#define	R_386_TLS_IE	15	/* Absolute address of GOT for -ve static TLS */
-#define	R_386_TLS_GOTIE	16	/* GOT entry for negative static TLS block */
-#define	R_386_TLS_LE	17	/* Negative offset relative to static TLS */
-#define	R_386_TLS_GD	18	/* 32 bit offset to GOT (index,off) pair */
-#define	R_386_TLS_LDM	19	/* 32 bit offset to GOT (index,zero) pair */
-#define	R_386_TLS_GD_32	24	/* 32 bit offset to GOT (index,off) pair */
-#define	R_386_TLS_GD_PUSH 25	/* pushl instruction for Sun ABI GD sequence */
-#define	R_386_TLS_GD_CALL 26	/* call instruction for Sun ABI GD sequence */
-#define	R_386_TLS_GD_POP 27	/* popl instruction for Sun ABI GD sequence */
-#define	R_386_TLS_LDM_32 28	/* 32 bit offset to GOT (index,zero) pair */
-#define	R_386_TLS_LDM_PUSH 29	/* pushl instruction for Sun ABI LD sequence */
-#define	R_386_TLS_LDM_CALL 30	/* call instruction for Sun ABI LD sequence */
-#define	R_386_TLS_LDM_POP 31	/* popl instruction for Sun ABI LD sequence */
-#define	R_386_TLS_LDO_32 32	/* 32 bit offset from start of TLS block */
-#define	R_386_TLS_IE_32	33	/* 32 bit offset to GOT static TLS offset entry */
-#define	R_386_TLS_LE_32	34	/* 32 bit offset within static TLS block */
-#define	R_386_TLS_DTPMOD32 35	/* GOT entry containing TLS index */
-#define	R_386_TLS_DTPOFF32 36	/* GOT entry containing TLS offset */
-#define	R_386_TLS_TPOFF32 37	/* GOT entry of -ve static TLS offset */
-
-#define	R_386_COUNT	38	/* Count of defined relocation types. */
+#define	R_386_NONE          0
+#define	R_386_32            1
+#define	R_386_PC32          2
+#define	R_386_GOT32         3
+#define	R_386_PLT32         4
+#define	R_386_COPY          5
+#define	R_386_GLOB_DAT      6
+#define	R_386_JMP_SLOT      7
+#define	R_386_RELATIVE      8
+#define	R_386_GOTOFF        9
+#define	R_386_GOTPC         10
+#define	R_386_TLS_TPOFF     14
+#define	R_386_TLS_IE        15
+#define	R_386_TLS_GOTIE     16
+#define	R_386_TLS_LE        17
+#define	R_386_TLS_GD        18
+#define	R_386_TLS_LDM       19
+#define	R_386_TLS_GD_32     24
+#define	R_386_TLS_GD_PUSH   25
+#define	R_386_TLS_GD_CALL   26
+#define	R_386_TLS_GD_POP    27
+#define	R_386_TLS_LDM_32    28
+#define	R_386_TLS_LDM_PUSH  29
+#define	R_386_TLS_LDM_CALL  30
+#define	R_386_TLS_LDM_POP   31
+#define	R_386_TLS_LDO_32    32
+#define	R_386_TLS_IE_32     33
+#define	R_386_TLS_LE_32     34
+#define	R_386_TLS_DTPMOD32  35
+#define	R_386_TLS_DTPOFF32  36
+#define	R_386_TLS_TPOFF32   37
+#define	R_386_TLS_GOTDESC   39
+#define	R_386_TLS_DESC_CALL 40
+#define	R_386_TLS_DESC      41
+#define	R_386_IRELATIVE     42
+#define	R_386_GOT32X        43
 
 #define	R_PPC_NONE		0	/* No relocation. */
 #define	R_PPC_ADDR32		1
