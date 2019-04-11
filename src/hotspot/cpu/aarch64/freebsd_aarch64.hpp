#ifndef CPU_AARCH64_VM_FREEBSD_AARCH64_HPP
#define CPU_AARCH64_VM_FREEBSD_AARCH64_HPP

// for FreeBSD-11.2
#ifndef ID_AA64PFR0_ADV_SIMD_HP
#define	ID_AA64PFR0_ADV_SIMD_HP	(0x1 << ID_AA64PFR0_ADV_SIMD_SHIFT)
#endif

#define	CPU_IMPL_ARM		0x41
#define	CPU_IMPL_BROADCOM	0x42
#define	CPU_IMPL_CAVIUM		0x43
#define	CPU_IMPL_DEC		0x44
#define	CPU_IMPL_INFINEON	0x49
#define	CPU_IMPL_FREESCALE	0x4D
#define	CPU_IMPL_NVIDIA		0x4E
#define	CPU_IMPL_APM		0x50
#define	CPU_IMPL_QUALCOMM	0x51
#define	CPU_IMPL_MARVELL	0x56
#define	CPU_IMPL_INTEL		0x69

/* ARM Part numbers */
#define	CPU_PART_FOUNDATION	0xD00
#define	CPU_PART_CORTEX_A35	0xD04
#define	CPU_PART_CORTEX_A53	0xD03
#define	CPU_PART_CORTEX_A55	0xD05
#define	CPU_PART_CORTEX_A57	0xD07
#define	CPU_PART_CORTEX_A72	0xD08
#define	CPU_PART_CORTEX_A73	0xD09
#define	CPU_PART_CORTEX_A75	0xD0A

/* Cavium Part numbers */
#define	CPU_PART_THUNDERX	0x0A1
#define	CPU_PART_THUNDERX_81XX	0x0A2
#define	CPU_PART_THUNDERX_83XX	0x0A3
#define	CPU_PART_THUNDERX2	0x0AF

#define	CPU_REV_THUNDERX_1_0	0x00
#define	CPU_REV_THUNDERX_1_1	0x01

#define	CPU_REV_THUNDERX2_0	0x00

#define	CPU_IMPL(midr)	(((midr) >> 24) & 0xff)
#define	CPU_PART(midr)	(((midr) >> 4) & 0xfff)
#define	CPU_VAR(midr)	(((midr) >> 20) & 0xf)
#define	CPU_REV(midr)	(((midr) >> 0) & 0xf)


struct cpu_desc {
	u_int		cpu_impl;
	u_int		cpu_part_num;
	u_int		cpu_variant;
	u_int		cpu_revision;
	const char	*cpu_impl_name;
	const char	*cpu_part_name;
};

struct cpu_parts {
	u_int		part_id;
	const char	*part_name;
};
#define	CPU_PART_NONE	{ 0, "Unknown Processor" }

struct cpu_implementers {
	u_int			impl_id;
	const char		*impl_name;
	/*
	 * Part number is implementation defined
	 * so each vendor will have its own set of values and names.
	 */
	const struct cpu_parts	*cpu_parts;
};
#define	CPU_IMPLEMENTER_NONE	{ 0, "Unknown Implementer", cpu_parts_none }

/*
 * Per-implementer table of (PartNum, CPU Name) pairs.
 */
/* ARM Ltd. */
static const struct cpu_parts cpu_parts_arm[] = {
	{ CPU_PART_FOUNDATION, "Foundation-Model" },
	{ CPU_PART_CORTEX_A35, "Cortex-A35" },
	{ CPU_PART_CORTEX_A53, "Cortex-A53" },
	{ CPU_PART_CORTEX_A55, "Cortex-A55" },
	{ CPU_PART_CORTEX_A57, "Cortex-A57" },
	{ CPU_PART_CORTEX_A72, "Cortex-A72" },
	{ CPU_PART_CORTEX_A73, "Cortex-A73" },
	{ CPU_PART_CORTEX_A75, "Cortex-A75" },
	CPU_PART_NONE,
};
/* Cavium */
static const struct cpu_parts cpu_parts_cavium[] = {
	{ CPU_PART_THUNDERX, "ThunderX" },
	{ CPU_PART_THUNDERX2, "ThunderX2" },
	CPU_PART_NONE,
};

/* Unknown */
static const struct cpu_parts cpu_parts_none[] = {
	CPU_PART_NONE,
};

/*
 * Implementers table.
 */
const struct cpu_implementers cpu_implementers[] = {
	{ CPU_IMPL_ARM,		"ARM",		cpu_parts_arm },
	{ CPU_IMPL_BROADCOM,	"Broadcom",	cpu_parts_none },
	{ CPU_IMPL_CAVIUM,	"Cavium",	cpu_parts_cavium },
	{ CPU_IMPL_DEC,		"DEC",		cpu_parts_none },
	{ CPU_IMPL_INFINEON,	"IFX",		cpu_parts_none },
	{ CPU_IMPL_FREESCALE,	"Freescale",	cpu_parts_none },
	{ CPU_IMPL_NVIDIA,	"NVIDIA",	cpu_parts_none },
	{ CPU_IMPL_APM,		"APM",		cpu_parts_none },
	{ CPU_IMPL_QUALCOMM,	"Qualcomm",	cpu_parts_none },
	{ CPU_IMPL_MARVELL,	"Marvell",	cpu_parts_none },
	{ CPU_IMPL_INTEL,	"Intel",	cpu_parts_none },
	CPU_IMPLEMENTER_NONE,
};

#endif
