#define __POWER_PROTECTER_EFLAG_SET__						1
#define __POWER_PROTECTER_EFLAG_RESET__						0

typedef enum _POWER_PROTECTER_EFLAGINDEX {
	PP_ER_CF = 0,
	PP_ER_PF = 2,
	PP_ER_AF = 4,
	PP_ER_ZF = 6,
	PP_ER_SF = 7,
	PP_ER_TF = 8,
	PP_ER_IF = 9,
	PP_ER_DF = 10,
	PP_ER_OF = 11,

	PP_ER_IOPL = 12,
	PP_ER_NT = 14,
	PP_ER_RF = 16,
	PP_ER_VM = 17,
	PP_ER_AC = 18,
	PP_ER_VIF = 19,
	PP_ER_VIP = 20,
	PP_ER_ID = 21
} POWER_PROTECTER_EFLAGINDEX;

#define __POWER_PROTECTER_CPU_EFLAG_GET__(EFlag, bEFlagIndex)				((bEFlagIndex) == PP_ER_IOPL) \
																			? \
																			(__byte)((EFlag) >> (bEFlagIndex) & 0x03) \
																			: \
																			(__byte)((EFlag) >> (bEFlagIndex) & 0x01)

#define __POWER_PROTECTER_CPU_EFLAG_SET__(EFlag, bEFlagIndex, bNewValue)	(EFlag) = \
																			((bNewValue) == 1) \
																			? \
																			(EFlag) | ((__dword)1 << (bEFlagIndex)) \
																			: \
																			(EFlag) & (~((__dword)1 << (bEFlagIndex)))


__byte __INTERNAL_FUNC__ PowerProtecter_Test_00(__dword dwEFlag) {
	/* O */
	__byte bOF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_OF);
	return ((bOF == __POWER_PROTECTER_EFLAG_SET__) ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_01(__dword dwEFlag) {
	/* NO */
	__byte bOF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_OF);
	return ((bOF == __POWER_PROTECTER_EFLAG_SET__) ? 0 : 1);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_02(__dword dwEFlag) {
	/* C */
	__byte bCF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_CF);
	return ((bCF == __POWER_PROTECTER_EFLAG_SET__) ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_03(__dword dwEFlag) {
	/* NC */
	__byte bCF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_CF);
	return ((bCF == __POWER_PROTECTER_EFLAG_SET__) ? 0 : 1);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_04(__dword dwEFlag) {
	/* Z */
	__byte bZF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_ZF);
	return ((bZF == __POWER_PROTECTER_EFLAG_SET__) ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_05(__dword dwEFlag) {
	/* NZ */
	__byte bZF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_ZF);
	return ((bZF == __POWER_PROTECTER_EFLAG_SET__) ? 0 : 1);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_06(__dword dwEFlag) {
	/* BE/NA */
	__byte bCF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_CF);
	__byte bZF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_ZF);
	return (((bCF == __POWER_PROTECTER_EFLAG_SET__) || (bZF == __POWER_PROTECTER_EFLAG_SET__)) ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_07(__dword dwEFlag) {
	/* NBE/A */
	__byte bCF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_CF);
	__byte bZF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_ZF);
	return (((bCF == __POWER_PROTECTER_EFLAG_RESET__) && (bZF == __POWER_PROTECTER_EFLAG_RESET__)) ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_08(__dword dwEFlag) {
	/* S */
	__byte bSF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_SF);
	return (bSF ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_09(__dword dwEFlag) {
	/* NS */
	__byte bSF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_SF);
	return (bSF ? 0 : 1);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_0A(__dword dwEFlag) {
	/* P */
	__byte bPF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_PF);
	return (bPF ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_0B(__dword dwEFlag) {
	/* NP */
	__byte bPF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_PF);
	return (bPF ? 0 : 1);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_0C(__dword dwEFlag) {
	/* L/NGE */
	__byte bSF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_SF);
	__byte bOF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_OF);
	return ((bSF != bOF) ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_0D(__dword dwEFlag) {
	/*NL/GE */
	__byte bSF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_SF);
	__byte bOF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_OF);
	return ((bSF == bOF) ? 1 : 0);
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_0E(__dword dwEFlag) {
	/* LE/NG */
	__byte bZF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_ZF);
	__byte bSF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_SF);
	__byte bOF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_OF);
	return ((bZF == __POWER_PROTECTER_EFLAG_SET__) || ((bSF != bOF) ? 1 : 0));
}

__byte __INTERNAL_FUNC__ PowerProtecter_Test_0F(__dword dwEFlag) {
	/*NL/GE */
	__byte bZF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_ZF);
	__byte bSF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_SF);
	__byte bOF = __POWER_PROTECTER_CPU_EFLAG_GET__(dwEFlag, PP_ER_OF);
	return ((bZF == __POWER_PROTECTER_EFLAG_RESET__) && ((bSF == bOF) ? 1 : 0));
}
