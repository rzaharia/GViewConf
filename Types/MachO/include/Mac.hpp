#pragma once

#include "GView.hpp"

namespace GView::Type::MachO::MAC
{
constexpr uint32_t MH_MAGIC    = 0xfeedface; /* the mach magic number */
constexpr uint32_t MH_CIGAM    = 0xcefaedfe; /* NXSwapInt(MH_MAGIC) */
constexpr uint32_t MH_MAGIC_64 = 0xfeedfacf; /* the 64-bit mach magic number */
constexpr uint32_t MH_CIGAM_64 = 0xcffaedfe; /* NXSwapInt(MH_MAGIC_64) */

typedef int32_t cpu_type_t;
typedef int32_t cpu_subtype_t;
typedef int32_t cpu_threadtype_t;

constexpr uint32_t CPU_STATE_MAX = 3;

constexpr uint32_t CPU_STATE_USER   = 0;
constexpr uint32_t CPU_STATE_SYSTEM = 1;
constexpr uint32_t CPU_STATE_IDLE   = 2;

constexpr uint32_t CPU_ARCH_ABI64    = 0x1000000;
constexpr uint32_t CPU_ARCH_ABI64_32 = 0x2000000;

constexpr cpu_type_t CPU_TYPE_ANY         = -1;
constexpr cpu_type_t CPU_TYPE_VAX         = 1;
constexpr cpu_type_t CPU_TYPE_ROMP        = 2;
constexpr cpu_type_t CPU_TYPE_NS32032     = 4;
constexpr cpu_type_t CPU_TYPE_NS32332     = 5;
constexpr cpu_type_t CPU_TYPE_MC680x0     = 6;
constexpr cpu_type_t CPU_TYPE_I386        = 7;
constexpr cpu_type_t CPU_TYPE_X86_64      = (CPU_TYPE_I386 | CPU_ARCH_ABI64);
constexpr cpu_type_t CPU_TYPE_MIPS        = 8;
constexpr cpu_type_t CPU_TYPE_NS32532     = 9;
constexpr cpu_type_t CPU_TYPE_HPPA        = 11;
constexpr cpu_type_t CPU_TYPE_ARM         = 12;
constexpr cpu_type_t CPU_TYPE_MC88000     = 13;
constexpr cpu_type_t CPU_TYPE_SPARC       = 14;
constexpr cpu_type_t CPU_TYPE_I860        = 15; // big-endian
constexpr cpu_type_t CPU_TYPE_I860_LITTLE = 16; // little-endian
constexpr cpu_type_t CPU_TYPE_RS6000      = 17;
constexpr cpu_type_t CPU_TYPE_MC98000     = 18;
constexpr cpu_type_t CPU_TYPE_POWERPC     = 18;
constexpr cpu_type_t CPU_TYPE_POWERPC64   = (CPU_TYPE_POWERPC | CPU_ARCH_ABI64);
constexpr cpu_type_t CPU_TYPE_VEO         = 255;
constexpr cpu_type_t CPU_TYPE_ARM64       = (CPU_TYPE_ARM | CPU_ARCH_ABI64);
constexpr cpu_type_t CPU_TYPE_ARM64_32    = (CPU_TYPE_ARM | CPU_ARCH_ABI64_32);

/* Capability bits used in the definition of cpu_subtype. */
constexpr uint32_t CPU_SUBTYPE_MASK  = 0xff000000; /* mask for feature flags */
constexpr uint32_t CPU_SUBTYPE_LIB64 = 0x80000000; /* 64 bit libraries */

/* CPU subtype capability flags for ptrauth on arm64e platforms */
constexpr uint32_t CPU_SUBTYPE_ARM64_PTR_AUTH_MASK = 0x0f000000;

/* CPU subtype capability flags for ptrauth on arm64e platforms, take 2 */
constexpr uint32_t CPU_SUBTYPE_ARM64E_VERSIONED_ABI_MASK = 0x80000000;
constexpr uint32_t CPU_SUBTYPE_ARM64E_KERNEL_ABI_MASK    = 0x40000000;
constexpr uint32_t CPU_SUBTYPE_ARM64E_PTR_AUTH_MASK      = 0x3f000000;

constexpr cpu_subtype_t CPU_SUBTYPE_MULTIPLE = -1;

/* VAX subtypes (these do *not* necessary conform to the actual cpu ID assigned by DEC available via the SID register). */
constexpr cpu_subtype_t CPU_SUBTYPE_VAX_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX780  = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX785  = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX750  = 3;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX730  = 4;
constexpr cpu_subtype_t CPU_SUBTYPE_UVAXI   = 5;
constexpr cpu_subtype_t CPU_SUBTYPE_UVAXII  = 6;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX8200 = 7;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX8500 = 8;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX8600 = 9;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX8650 = 10;
constexpr cpu_subtype_t CPU_SUBTYPE_VAX8800 = 11;
constexpr cpu_subtype_t CPU_SUBTYPE_UVAXIII = 12;

/* ROMP subtypes. */
constexpr cpu_subtype_t CPU_SUBTYPE_RT_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_RT_PC  = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_RT_APC = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_RT_135 = 3;

/* 32032/32332/32532 subtypes. */

constexpr cpu_subtype_t CPU_SUBTYPE_MMAX_ALL     = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_MMAX_DPC     = 1; /* 032 CPU */
constexpr cpu_subtype_t CPU_SUBTYPE_SQT          = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_MMAX_APC_FPU = 3; /* 32081 FPU */
constexpr cpu_subtype_t CPU_SUBTYPE_MMAX_APC_FPA = 4; /* Weitek FPA */
constexpr cpu_subtype_t CPU_SUBTYPE_MMAX_XPC     = 5; /* 532 CPU */

/* I386 subtypes. */
constexpr cpu_subtype_t CPU_SUBTYPE_I386_ALL   = 3;
constexpr cpu_subtype_t CPU_SUBTYPE_X86_64_ALL = CPU_SUBTYPE_I386_ALL;
constexpr cpu_subtype_t CPU_SUBTYPE_386        = 3;
constexpr cpu_subtype_t CPU_SUBTYPE_486        = 4;
constexpr cpu_subtype_t CPU_SUBTYPE_486SX      = 4 + 128;
constexpr cpu_subtype_t CPU_SUBTYPE_586        = 5;
#define CPU_SUBTYPE_INTEL(f, m) ((cpu_subtype_t) (f) + ((m) << 4))
constexpr cpu_subtype_t CPU_SUBTYPE_PENT      = CPU_SUBTYPE_INTEL(5, 0);
constexpr cpu_subtype_t CPU_SUBTYPE_PENTPRO   = CPU_SUBTYPE_INTEL(6, 1);
constexpr cpu_subtype_t CPU_SUBTYPE_PENTII_M3 = CPU_SUBTYPE_INTEL(6, 3);
constexpr cpu_subtype_t CPU_SUBTYPE_PENTII_M5 = CPU_SUBTYPE_INTEL(6, 5);
constexpr cpu_subtype_t CPU_SUBTYPE_PENTIUM_4 = CPU_SUBTYPE_INTEL(10, 0);

#define CPU_SUBTYPE_INTEL_FAMILY(x) ((x) &15)
constexpr uint32_t CPU_SUBTYPE_INTEL_FAMILY_MAX = 15;

#define CPU_SUBTYPE_INTEL_MODEL(x) ((x) >> 4)
constexpr uint32_t CPU_SUBTYPE_INTEL_MODEL_ALL = 0;

constexpr cpu_subtype_t CPU_SUBTYPE_X86_64_H = 8; /* Haswell and compatible */

/* Mips subtypes. */
constexpr cpu_subtype_t CPU_SUBTYPE_MIPS_ALL    = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_MIPS_R2300  = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_MIPS_R2600  = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_MIPS_R2800  = 3;
constexpr cpu_subtype_t CPU_SUBTYPE_MIPS_R2000a = 4;

/* 680x0 subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_MC680x0_ALL  = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_MC68030      = 1; /* compat */
constexpr cpu_subtype_t CPU_SUBTYPE_MC68040      = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_MC68030_ONLY = 3;

/* HPPA subtypes for Hewlett-Packard HP-PA family of risc processors. Port by NeXT to 700 series. */
constexpr cpu_subtype_t CPU_SUBTYPE_HPPA_ALL    = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_HPPA_7100   = 0; /* compat */
constexpr cpu_subtype_t CPU_SUBTYPE_HPPA_7100LC = 1;

/* Acorn subtypes - Acorn Risc Machine */
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_ALL       = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_A500_ARCH = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_A500      = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_A440      = 3;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_M4        = 4;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V4T       = 5;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V6        = 6;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V5TEJ     = 7;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_XSCALE    = 8;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V7        = 9;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V7F       = 10; /* Cortex A9 */
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V7S       = 11; /* Swift */
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V7K       = 12; /* Kirkwood40 */
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V6M       = 14; /* Not meant to be run under xnu */
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V7M       = 15; /* Not meant to be run under xnu */
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V7EM      = 16; /* Not meant to be run under xnu */
constexpr cpu_subtype_t CPU_SUBTYPE_ARM_V8        = 13;

constexpr cpu_subtype_t CPU_SUBTYPE_ARM64_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM64_V8  = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_ARM64E    = 2;

constexpr cpu_subtype_t CPU_SUBTYPE_ARM64_32_V8 = 1;

/* MC88000 subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_MC88000_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_MMAX_JPC    = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_MC88100     = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_MC88110     = 2;

/* MC98000 (PowerPC) subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_MC98000_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_MC98601     = 1;

/* I860 subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_I860_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_I860_860 = 1;

/* I860 subtypes for NeXT-internal backwards compatability. */
constexpr cpu_subtype_t CPU_SUBTYPE_LITTLE_ENDIAN = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_BIG_ENDIAN    = 1;

/* I860_LITTLE subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_I860_LITTLE_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_I860_LITTLE     = 1;

/* RS6000 subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_RS6000_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_RS6000     = 1;

/* Sun4 subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_SUN4_ALL = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_SUN4_260 = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_SUN4_110 = 2;

constexpr cpu_subtype_t CPU_SUBTYPE_SPARC_ALL = 0;

/* PowerPC subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_ALL   = 0;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_601   = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_602   = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_603   = 3;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_603e  = 4;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_603ev = 5;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_604   = 6;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_604e  = 7;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_620   = 8;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_750   = 9;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_7400  = 10;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_7450  = 11;
constexpr cpu_subtype_t CPU_SUBTYPE_POWERPC_970   = 100;

/* VEO subtypes */
constexpr cpu_subtype_t CPU_SUBTYPE_VEO_1   = 1;
constexpr cpu_subtype_t CPU_SUBTYPE_VEO_2   = 2;
constexpr cpu_subtype_t CPU_SUBTYPE_VEO_3   = 3;
constexpr cpu_subtype_t CPU_SUBTYPE_VEO_4   = 4;
constexpr cpu_subtype_t CPU_SUBTYPE_VEO_ALL = CPU_SUBTYPE_VEO_2;

enum class FileType : uint32_t
{
    OBJECT      = 0x1, /* relocatable object file */
    EXECUTE     = 0x2, /* demand paged executable file */
    FVMLIB      = 0x3, /* fixed VM shared library file */
    CORE        = 0x4, /* core file */
    PRELOAD     = 0x5, /* preloaded executable file */
    DYLIB       = 0x6, /* dynamically bound shared library */
    BUNDLE      = 0x8, /* dynamically bound bundle file */
    DYLIB_STUB  = 0x9, /* shared library stub for static | linking only, no section contents */
    DSYM        = 0xA, /* companion file with only debug | sections */
    KEXT_BUNDLE = 0xB, /* x86_64 kexts */
};

struct mach_header
{
    uint32_t magic;           /* mach magic number identifier */
    cpu_type_t cputype;       /* cpu specifier */
    cpu_subtype_t cpusubtype; /* machine specifier */
    FileType filetype;        /* type of file */
    uint32_t ncmds;           /* number of load commands */
    uint32_t sizeofcmds;      /* the size of all the load commands */
    uint32_t flags;           /* flags */
    uint32_t reserved;        /* reserved (for x64 only!) */
};

enum class ByteOrder
{
    Unknown,
    LittleEndian,
    BigEndian
};

struct ArchInfo
{
    std::string name;
    cpu_type_t cputype;
    cpu_subtype_t cpusubtype;
    ByteOrder byteorder;
    std::string description;
};

enum class MachHeaderFlags : uint32_t
{
    NOUNDEFS                      = 0x1,
    INCRLINK                      = 0x2,
    DYLDLINK                      = 0x4,
    BINDATLOAD                    = 0x8,
    PREBOUND                      = 0x10,
    SPLIT_SEGS                    = 0x20,
    LAZY_INIT                     = 0x40,
    TWOLEVEL                      = 0x80,
    FORCE_FLAT                    = 0x100,
    NOMULTIDEFS                   = 0x200,
    NOFIXPREBINDING               = 0x400,
    PREBINDABLE                   = 0x800,
    ALLMODSBOUND                  = 0x1000,
    SUBSECTIONS_VIA_SYMBOLS       = 0x2000,
    CANONICAL                     = 0x4000,
    WEAK_DEFINES                  = 0x8000,
    BINDS_TO_WEAK                 = 0x10000,
    ALLOW_STACK_EXECUTION         = 0x20000,
    ROOT_SAFE                     = 0x40000,
    SETUID_SAFE                   = 0x80000,
    NO_REEXPORTED_DYLIBS          = 0x100000,
    PIE                           = 0x200000,
    DEAD_STRIPPABLE_DYLIB         = 0x400000,
    HAS_TLV_DESCRIPTORS           = 0x800000,
    NO_HEAP_EXECUTION             = 0x1000000,
    APP_EXTENSION_SAFE            = 0x02000000,
    NLIST_OUTOFSYNC_WITH_DYLDINFO = 0x04000000,
    SIM_SUPPORT                   = 0x08000000
};

enum class LoadCommandType : uint32_t
{
    REQ_DYLD                 = 0x80000000,
    SEGMENT                  = 0x1,
    SYMTAB                   = 0x2,
    SYMSEG                   = 0x3,
    THREAD                   = 0x4,
    UNIXTHREAD               = 0x5,
    LOADFVMLIB               = 0x6,
    IDFVMLIB                 = 0x7,
    IDENT                    = 0x8,
    FVMFILE                  = 0x9,
    PREPAGE                  = 0xa,
    DYSYMTAB                 = 0xb,
    LOAD_DYLIB               = 0xc,
    ID_DYLIB                 = 0xd,
    LOAD_DYLINKER            = 0xe,
    ID_DYLINKER              = 0xf,
    PREBOUND_DYLIB           = 0x10,
    ROUTINES                 = 0x11,
    SUB_FRAMEWORK            = 0x12,
    SUB_UMBRELLA             = 0x13,
    SUB_CLIENT               = 0x14,
    SUB_LIBRARY              = 0x15,
    TWOLEVEL_HINTS           = 0x16,
    PREBIND_CKSUM            = 0x17,
    LOAD_WEAK_DYLIB          = (0x18 | REQ_DYLD),
    SEGMENT_64               = 0x19,
    ROUTINES_64              = 0x1a,
    UUID                     = 0x1b,
    RPATH                    = (0x1c | REQ_DYLD),
    CODE_SIGNATURE           = 0x1d,
    SEGMENT_SPLIT_INFO       = 0x1e,
    REEXPORT_DYLIB           = (0x1f | REQ_DYLD),
    LAZY_LOAD_DYLIB          = 0x20,
    ENCRYPTION_INFO          = 0x21,
    DYLD_INFO                = 0x22,
    DYLD_INFO_ONLY           = (0x22 | REQ_DYLD),
    LOAD_UPWARD_DYLIB        = (0x23 | REQ_DYLD),
    VERSION_MIN_MACOSX       = 0x24,
    VERSION_MIN_IPHONEOS     = 0x25,
    FUNCTION_STARTS          = 0x26,
    DYLD_ENVIRONMENT         = 0x27,
    MAIN                     = (0x28 | REQ_DYLD),
    DATA_IN_CODE             = 0x29,
    SOURCE_VERSION           = 0x2A,
    DYLIB_CODE_SIGN_DRS      = 0x2B,
    ENCRYPTION_INFO_64       = 0x2C,
    LINKER_OPTION            = 0x2D,
    LINKER_OPTIMIZATION_HINT = 0x2E,
    VERSION_MIN_TVOS         = 0x2F,
    VERSION_MIN_WATCHOS      = 0x30,
    BUILD_VERSION            = 0x31,
    NOTE                     = 0x32,
    DYLD_EXPORTS_TRIE        = (0x33 | REQ_DYLD),
    DYLD_CHAINED_FIXUPS      = (0x34 | REQ_DYLD),
    FILESET_ENTRY            = (0x35 | REQ_DYLD)
};

struct load_command
{
    LoadCommandType cmd; /* type of load command */
    uint32_t cmdsize;    /* total size of command in bytes */
};

union lc_str
{
    uint32_t offset; /* offset to the string */
    uint64_t ptr;    /* pointer to the string */
};

enum class VMProtectionFlags : uint32_t
{
    NONE      = 0x0,
    READ      = 0x1,                      /* read permission */
    WRITE     = 0x2,                      /* write permission */
    EXECUTE   = 0x4,                      /* execute permission */
    DEFAULT   = (READ | WRITE),           /* The default protection for newly-created virtual memory. */
    ALL       = (READ | WRITE | EXECUTE), /* The maximum privileges possible, for parameter checking. */
    NO_CHANGE = 0x8,  /* An invalid protection value. Used only by memory_object_lock_request to indicate no change to page locks.  Using
                       -1 here is a bad idea because it looks like VM_PROT::ALL and then some. */
    COPY = 0x10,      /* When a caller finds that he cannot obtain write permission on a mapped entry, the following flag can be used.  The
                       * entry will be made "needs copy" effectively copying the object (using COW), and write permission will be added to
                       * the maximum protections for the associated entry. */
    WANTS_COPY = 0x10 /* Another invalid protection value. Used only by memory_object_data_request upon an object which has specified a
                       * copy_call copy strategy. It is used when the kernel wants a page belonging to a copy of the object, and is only
                       * asking the object as a result of following a shadow chain. This solves the race between pages being pushed up
                       * by the memory manager and the kernel walking down the shadow chain.
                       */
};

struct segment_command
{
    LoadCommandType cmd; /* LC_SEGMENT */
    uint32_t cmdsize;    /* includes sizeof section structs */
    char segname[16];    /* segment name */
    uint32_t vmaddr;     /* memory address of this segment */
    uint32_t vmsize;     /* memory size of this segment */
    uint32_t fileoff;    /* file offset of this segment */
    uint32_t filesize;   /* amount to map from the file */
    uint32_t maxprot;    /* maximum VM protection */
    uint32_t initprot;   /* initial VM protection */
    uint32_t nsects;     /* number of sections in segment */
    uint32_t flags;      /* flags */
};

struct segment_command_64
{
    LoadCommandType cmd; /* LC_SEGMENT_64 */
    uint32_t cmdsize;    /* includes sizeof section_64 structs */
    char segname[16];    /* segment name */
    uint64_t vmaddr;     /* memory address of this segment */
    uint64_t vmsize;     /* memory size of this segment */
    uint64_t fileoff;    /* file offset of this segment */
    uint64_t filesize;   /* amount to map from the file */
    uint32_t maxprot;    /* maximum VM protection */
    uint32_t initprot;   /* initial VM protection */
    uint32_t nsects;     /* number of sections in segment */
    uint32_t flags;      /* flags */
};

enum class SegmentCommandFlags : uint32_t
{
    NONE   = 0x0,
    HIGHVM = 0x01,  /* The file contents for this segment is for the high part of the VM space, the low part is zero filled (for stacks
                       in  core files). */
    FVMLIB  = 0x02, /* This segment is the VM that is allocated by a fixed VM library, for overlap checking in the link editor */
    NORELOC = 0x04, /* This segment has nothing that was relocated in it and nothing relocated to it, that is it maybe safely replaced
                       without relocation. */
    PROTECTED_VERSION_1 = 0x08, /* This segment is protected. If the segment starts at file offset 0, the first page of the segment is
                                   not protected.  All other pages of the segment are protected. */
    READONLY = 0x10             /* This segment is made read-only after fixups */
};

struct section
{                       /* for 32-bit architectures */
    char sectname[16];  /* name of this section */
    char segname[16];   /* segment this section goes in */
    uint32_t addr;      /* memory address of this section */
    uint32_t size;      /* size in bytes of this section */
    uint32_t offset;    /* file offset of this section */
    uint32_t align;     /* section alignment (power of 2) */
    uint32_t reloff;    /* file offset of relocation entries */
    uint32_t nreloc;    /* number of relocation entries */
    uint32_t flags;     /* flags (section type and attributes)*/
    uint32_t reserved1; /* reserved (for offset or index) */
    uint32_t reserved2; /* reserved (for count or sizeof) */
};

struct section_64
{                       /* for 64-bit architectures */
    char sectname[16];  /* name of this section */
    char segname[16];   /* segment this section goes in */
    uint64_t addr;      /* memory address of this section */
    uint64_t size;      /* size in bytes of this section */
    uint32_t offset;    /* file offset of this section */
    uint32_t align;     /* section alignment (power of 2) */
    uint32_t reloff;    /* file offset of relocation entries */
    uint32_t nreloc;    /* number of relocation entries */
    uint32_t flags;     /* flags (section type and attributes)*/
    uint32_t reserved1; /* reserved (for offset or index) */
    uint32_t reserved2; /* reserved (for count or sizeof) */
    uint32_t reserved3; /* reserved */
};

constexpr uint32_t SECTION_TYPE       = 0x000000ff; /* 256 section types */
constexpr uint32_t SECTION_ATTRIBUTES = 0xffffff00; /*  24 section attributes */

/* The flags field of a section structure is separated into two parts a section type and section attributes.  The section types are mutually
 * exclusive (it can only have one type) but the section attributes are not (it may have more than one attribute). */
enum class SectionType : uint32_t
{
    REGULAR                             = 0x00, /* regular section */
    ZEROFILL                            = 0x01, /* zero fill on demand section */
    CSTRING_LITERALS                    = 0x02, /* section with only literal C strings*/
    _4BYTE_LITERALS                     = 0x03, /* section with only 4 byte literals */
    _8BYTE_LITERALS                     = 0x04, /* section with only 8 byte literals */
    LITERAL_POINTERS                    = 0x05, /* section with only pointers to literals */
    NON_LAZY_SYMBOL_POINTERS            = 0x06, /* section with only non-lazy symbol pointers */
    LAZY_SYMBOL_POINTERS                = 0x07, /* section with only lazy symbol pointers */
    SYMBOL_STUBS                        = 0x08, /* section with only symbol stubs, byte size of stub in the reserved2 field */
    MOD_INIT_FUNC_POINTERS              = 0x09, /* section with only function pointers for initialization*/
    MOD_TERM_FUNC_POINTERS              = 0x0a, /* section with only function pointers for termination */
    COALESCED                           = 0x0b, /* section contains symbols that are to be coalesced */
    GB_ZEROFILL                         = 0x0c, /* zero fill on demand section (that can be larger than 4 gigabytes) */
    INTERPOSING                         = 0x0d, /* section with only pairs of function pointers for interposing */
    _16BYTE_LITERALS                    = 0x0e, /* section with only 16 byte literals */
    DTRACE_DOF                          = 0x0f, /* section contains DTrace Object Format */
    LAZY_DYLIB_SYMBOL_POINTERS          = 0x10, /* section with only lazy symbol pointers to lazy loaded dylibs */
    THREAD_LOCAL_REGULAR                = 0x11, /* template of initial values for TLVs */
    THREAD_LOCAL_ZEROFILL               = 0x12, /* template of initial values for TLVs */
    THREAD_LOCAL_VARIABLES              = 0x13, /* TLV descriptors */
    THREAD_LOCAL_VARIABLE_POINTERS      = 0x14, /* pointers to TLV descriptors */
    THREAD_LOCAL_INIT_FUNCTION_POINTERS = 0x15  /* functions to call to initialize TLV values */
};

enum class SectionAttributtes : uint32_t
{
    USR                 = 0xff000000, /* User setable attributes */
    PURE_INSTRUCTIONS   = 0x80000000, /* section contains only true machine instructions */
    NO_TOC              = 0x40000000, /* section contains coalesced symbols that are not to be in a ranlib table of contents */
    STRIP_STATIC_SYMS   = 0x20000000, /* ok to strip static symbols in this section in files with the MH_DYLDLINK flag */
    NO_DEAD_STRIP       = 0x10000000, /* no dead stripping */
    LIVE_SUPPORT        = 0x08000000, /* blocks are live if they reference live blocks */
    SELF_MODIFYING_CODE = 0x04000000, /* Used with i386 code stubs written on by dyld */
    DEBUG               = 0x02000000, /* a debug section */
    SYS                 = 0x00ffff00, /* system setable attributes */
    SOME_INSTRUCTIONS   = 0x00000400, /* section contains some machine instructions */
    EXT_RELOC           = 0x00000200, /* section has external relocation entries */
    LOC_RELOC           = 0x00000100  /* section has local relocation entries */
};

struct dyld_info_command
{
    LoadCommandType cmd;     /* LC_DYLD_INFO or LC_DYLD_INFO_ONLY */
    uint32_t cmdsize;        /* sizeof(struct dyld_info_command) */
    uint32_t rebase_off;     /* file offset to rebase info  */
    uint32_t rebase_size;    /* size of rebase info   */
    uint32_t bind_off;       /* file offset to binding info   */
    uint32_t bind_size;      /* size of binding info  */
    uint32_t weak_bind_off;  /* file offset to weak binding info   */
    uint32_t weak_bind_size; /* size of weak binding info  */
    uint32_t lazy_bind_off;  /* file offset to lazy binding info */
    uint32_t lazy_bind_size; /* size of lazy binding infs */
    uint32_t export_off;     /* file offset to lazy binding info */
    uint32_t export_size;    /* size of lazy binding infs */
};

struct dylib
{
    union lc_str name;              /* library's path name */
    uint32_t timestamp;             /* library's build time stamp */
    uint32_t current_version;       /* library's current version number */
    uint32_t compatibility_version; /* library's compatibility vers number*/
};

struct dylib_command
{
    LoadCommandType cmd; /* LC_ID_DYLIB, LC_LOAD_{,WEAK_}DYLIB, LC_REEXPORT_DYLIB */
    uint32_t cmdsize;    /* includes pathname string */
    dylib dylib;         /* the library identification */
};

struct entry_point_command
{
    LoadCommandType cmd; /* LC_MAIN only used in MH_EXECUTE filetypes */
    uint32_t cmdsize;    /* 24 */
    uint64_t entryoff;   /* file (__TEXT) offset of main() */
    uint64_t stacksize;  /* if not zero, initial stack size */
};

struct symtab_command
{
    LoadCommandType cmd; /* LC_SYMTAB */
    uint32_t cmdsize;    /* sizeof(struct symtab_command) */
    uint32_t symoff;     /* symbol table offset */
    uint32_t nsyms;      /* number of symbol table entries */
    uint32_t stroff;     /* string table offset */
    uint32_t strsize;    /* string table size in bytes */
};

struct nlist
{
    union
    {
        // char* n_name; /* for use when in-core */
        uint32_t n_strx; /* index into the string table */
    } n_un;
    uint8_t n_type;   /* type flag, see below */
    uint8_t n_sect;   /* section number or NO_SECT */
    int16_t n_desc;   /* see <mach-o/stab.h> */
    uint32_t n_value; /* value of this symbol (or stab offset) */
};

struct nlist_64
{
    union
    {
        uint32_t n_strx; /* index into the string table */
    } n_un;
    uint8_t n_type;   /* type flag, see below */
    uint8_t n_sect;   /* section number or NO_SECT */
    uint16_t n_desc;  /* see <mach-o/stab.h> -> description field */
    uint64_t n_value; /* value of this symbol (or stab offset) */
};

/* Symbols with a index into the string table of zero (n_un.n_strx == 0) are defined to have a null, "", name. Therefore all string indexes
 * to non null names must not have a zero string index.  This is bit historical information that has never been well documented. */

// n_type field
enum class N_TYPE
{
    STAB = 0xe0, /* if any of these bits set, a symbolic debugging entry */
    PEXT = 0x10, /* private external symbol bit */
    TYPE = 0x0e, /* mask for the type bits */
    EXT  = 0x01  /* external symbol bit, set for external symbols */
};

// N_TYPE bits of the n_type field
enum class N_TYPE_BITS
{
    UNDF = 0x0,  /* undefined, n_sect == NO_SECT */
    ABS  = 0x2,  /* absolute, n_sect == NO_SECT */
    TEXT = 0x4,  /* text */
    DATA = 0x6,  /* data */
    BSS  = 0x8,  /* bss */
    SECT = 0xe,  /* defined in section number n_sect */
    PBUD = 0xc,  /* prebound undefined (defined in a dylib) */
    INDR = 0xa,  /* indirect */
    COMM = 0x12, /* common (internal to ld) */
    FN   = 0x1f  /* file name symbol */
};

constexpr uint32_t NO_SECT  = 0;   /* symbol is not in any section */
constexpr uint32_t MAX_SECT = 255; /* 1 thru 255 inclusive */

inline static uint16_t GET_COMM_ALIGN(uint16_t n_desc)
{
    return (((n_desc) >> 8) & 0x0f);
}

/* Reference type bits of the n_desc field of undefined symbols */
constexpr uint32_t REFERENCE_TYPE = 0x0F; // (0x07?)

/* types of references */
enum class ReferenceFlag
{
    UNDEFINED_NON_LAZY         = 0,
    UNDEFINED_LAZY             = 1,
    DEFINED                    = 2,
    PRIVATE_DEFINED            = 3,
    PRIVATE_UNDEFINED_NON_LAZY = 4,
    PRIVATE_UNDEFINED_LAZY     = 5
};

inline static uint16_t GET_LIBRARY_ORDINAL(uint16_t n_desc)
{
    return (((n_desc) >> 8) & 0xff);
}

enum class OrdinalType
{
    SELF_LIBRARY   = 0x00,
    MAX_LIBRARY    = 0xfd,
    DYNAMIC_LOOKUP = 0xfe,
    EXECUTABLE     = 0xff
};

enum class N_DESC_BIT_TYPE
{
    REFERENCED_DYNAMICALLY = 0x0010,
    /* The bit 0x0020 of the n_desc field is used for two non-overlapping purposes and has two different symbolic names, N_NO_DEAD_STRIP and
     N_DESC_DISCARDED. The N_NO_DEAD_STRIP bit of the n_desc field only ever appears in a relocatable .o file (MH_OBJECT filetype). And is
     used to indicate to the static link editor it is never to dead strip the symbol. */
    NO_DEAD_STRIP  = 0x0020, /* symbol is not to be dead stripped */
    DESC_DISCARDED = 0x0020, /* symbol is discarded */
    /* The N_WEAK_REF bit of the n_desc field indicates to the dynamic linker that the undefined symbol is allowed to be missing and is to
    have the address of zero when missing. */
    WEAK_REF = 0x0040, /* symbol is weak referenced */
    /* The N_WEAK_DEF bit of the n_desc field indicates to the staticand dynamic linkers that the symbol definition is weak, allowing a
    non-weak symbol to also be used which causes the weak definition to be discared.  Currently this is only supported for symbols in
    coalesed sections. */
    WEAK_DEF = 0x0080, /* coalesed symbol is a weak definition */
    /* The N_REF_TO_WEAK bit of the n_desc field indicates to the dynamic linker that the undefined symbol should be resolved using flat
       namespace searching. */
    REF_TO_WEAK   = 0x0080, /* reference to a weak symbol */
    ARM_THUMB_DEF = 0x0008, /* symbol is a Thumb function (ARM) */
    /* The N_SYMBOL_RESOLVER bit of the n_desc field indicates that the that the function is actually a resolver function and should be
       called to get the address of the real function to use. This bit is only available in .o files (MH_OBJECT filetype) */
    SYMBOL_RESOLVER = 0x0100,
    /* The N_ALT_ENTRY bit of the n_desc field indicates that the symbol is pinned to the previous content. */
    ALT_ENTRY = 0x0200
};

enum class N_STAB_TYPE
{
    GSYM    = 0x20, // global symbol
    FNAME   = 0x22, // F77 function name
    FUN     = 0x24, // procedure name
    STSYM   = 0x26, // data segment variable
    LCSYM   = 0x28, // bss segment variable
    MAIN    = 0x2a, // main function name
    BNSYM   = 0x2e, /* begin nsect sym: 0,,n_sect,0,address */
    PC      = 0x30, // global Pascal symbol
    OPT     = 0x3c, /* emitted with gcc2_compiled and in gcc source */
    RSYM    = 0x40, // register variable
    SLINE   = 0x44, // text segment line number
    ENSYM   = 0x4e, /* end nsect sym: 0,,n_sect,0,address */
    DSLINE  = 0x46, // data segment line number
    BSLINE  = 0x48, // bss segment line number
    SSYM    = 0x60, // structure/union element
    SO      = 0x64, // main source file name
    OSO     = 0x66, /* object file name: name,,0,0,st_mtime */
    LSYM    = 0x80, // stack variable
    BINCL   = 0x82, // include file beginning
    SOL     = 0x84, // included source file name
    PARAMS  = 0x86, /* compiler parameters: name,,NO_SECT,0,0 */
    VERSION = 0x88, /* compiler version: name,,NO_SECT,0,0 */
    OLEVEL  = 0x8A, /* compiler -O level: name,,NO_SECT,0,0 */
    PSYM    = 0xa0, // parameter variable
    EINCL   = 0xa2, // include file end
    ENTRY   = 0xa4, // alternate entry point
    LBRAC   = 0xc0, // left bracket
    EXCL    = 0xc2, // deleted include file
    RBRAC   = 0xe0, // right bracket
    BCOMM   = 0xe2, // begin common
    ECOMM   = 0xe4, // end common
    ECOML   = 0xe8, // end common (local name)
    LENG    = 0xfe  // length of preceding entry
};

enum class PlatformType : uint8_t
{
    UNKNOWN          = 0,
    MACOS            = 1,
    IOS              = 2,
    TVOS             = 3,
    WATCHOS          = 4,
    BRIDGEOS         = 5,
    MACCATALYST      = 6,
    IOSSIMULATOR     = 7,
    TVOSSIMULATOR    = 8,
    WATCHOSSIMULATOR = 9,
    DRIVERKIT        = 10,
    _11              = 11, // TODO: ??
    _12              = 12, // TODO: ??
    _13              = 13, // TODO: ??
};

enum class Tool
{
    CLANG = 1,
    SWIFT = 2,
    LD    = 3
};

struct source_version_command // The source_version_command is an optional load command containing the version of the sources used to build
                              // the binary.
{
    LoadCommandType cmd; /* LC_SOURCE_VERSION */
    uint32_t cmdsize;    // Size of the command, typically 16 bytes.
    uint64_t version;    // A.B.C.D.E packed as a24.b10.c10.d10.e10
};

struct uuid_command // The uuid load command contains a single 128-bit unique random number that identifies an object produced by the static
                    // link editor.
{
    LoadCommandType cmd; /* UUID */
    uint32_t cmdsize;
    uint8_t uuid[16];
};

struct linkedit_data_command // The uuid load command contains a single 128-bit unique random number that identifies an object produced by
                             // the static link editor.
{
    LoadCommandType cmd; // LC_CODE_SIGNATURE, LC_SEGMENT_SPLIT_INFO, LC_FUNCTION_STARTS, LC_DATA_IN_CODE, LC_DYLIB_CODE_SIGN_DRS,
                         // LC_LINKER_OPTIMIZATION_HINT, LC_DYLD_EXPORTS_TRIE, LC_DYLD_CHAINED_FIXUPS
    uint32_t cmdsize;    // Sizeof(struct linkedit_data_command).
    uint32_t dataoff;    // File offset of data in __LINKEDIT segment.
    uint32_t datasize;   // File size of data in __LINKEDIT segment.
};

enum class CodeSignFlags : uint32_t
{
    VALID                  = 0x00000001, /* dynamically valid */
    ADHOC                  = 0x00000002, /* ad hoc signed */
    GET_TASK_ALLOW         = 0x00000004, /* has get-task-allow entitlement */
    INSTALLER              = 0x00000008, /* has installer entitlement */
    FORCED_LV              = 0x00000010, /* Library Validation required by Hardened System Policy */
    INVALID_ALLOWED        = 0x00000020, /* (macOS Only) Page invalidation allowed by task port policy */
    HARD                   = 0x00000100, /* don't load invalid pages */
    KILL                   = 0x00000200, /* kill process if it becomes invalid */
    CHECK_EXPIRATION       = 0x00000400, /* force expiration checking */
    RESTRICT               = 0x00000800, /* tell dyld to treat restricted */
    ENFORCEMENT            = 0x00001000, /* require enforcement */
    REQUIRE_LV             = 0x00002000, /* require library validation */
    ENTITLEMENTS_VALIDATED = 0x00004000, /* code signature permits restricted entitlements */
    NVRAM_UNRESTRICTED     = 0x00008000, /* has com.apple.rootless.restricted-nvram-variables.heritable entitlement */
    RUNTIME                = 0x00010000, /* Apply hardened runtime policies */
    LINKER_SIGNED          = 0x00020000, /* Automatically signed by the linker */
    ALLOWED_MACHO          = (ADHOC | HARD | KILL | CHECK_EXPIRATION | RESTRICT | ENFORCEMENT | REQUIRE_LV | RUNTIME | LINKER_SIGNED),
    EXEC_SET_HARD          = 0x00100000, /* set CS_HARD on any exec'ed process */
    EXEC_SET_KILL          = 0x00200000, /* set CS_KILL on any exec'ed process */
    EXEC_SET_ENFORCEMENT   = 0x00400000, /* set CS_ENFORCEMENT on any exec'ed process */
    EXEC_INHERIT_SIP       = 0x00800000, /* set CS_INSTALLER on any exec'ed process */
    KILLED                 = 0x01000000, /* was killed by kernel for invalidity */
    DYLD_PLATFORM          = 0x02000000, /* dyld used to load this is a platform binary */
    PLATFORM_BINARY        = 0x04000000, /* this is a platform binary */
    PLATFORM_PATH          = 0x08000000, /* platform binary by the fact of path (osx only) */
    DEBUGGED               = 0x10000000, /* process is currently or has previously been debugged and allowed to run with invalid pages */
    SIGNED                 = 0x20000000, /* process has a signature (may have gone invalid) */
    DEV_CODE               = 0x40000000, /* code is dev signed, cannot be loaded into prod signed code */
    DATAVAULT_CONTROLLER   = 0x80000000, /* has Data Vault controller entitlement */
    ENTITLEMENT_FLAGS      = (GET_TASK_ALLOW | INSTALLER | DATAVAULT_CONTROLLER | NVRAM_UNRESTRICTED),
};

enum class CodeSignExecSegFlags
{
    MAIN_BINARY     = 0x01,  /* executable segment denotes main binary */
    ALLOW_UNSIGNED  = 0x10,  /* allow unsigned pages (for debugging) */
    DEBUGGER        = 0x20,  /* main binary is debugger */
    JIT             = 0x40,  /* JIT enabled */
    SKIP_LV         = 0x80,  /* OBSOLETE: skip library validation */
    CAN_LOAD_CDHASH = 0x100, /* can bless cdhash for execution */
    CAN_EXEC_CDHASH = 0x200, /* can execute blessed cdhash */
};

enum class CodeSignMagic : uint32_t
{
    CSMAGIC_REQUIREMENT            = 0xfade0c00, /* single Requirement blob */
    CSMAGIC_REQUIREMENTS           = 0xfade0c01, /* Requirements vector (internal requirements) */
    CSMAGIC_CODEDIRECTORY          = 0xfade0c02, /* CodeDirectory blob */
    CSMAGIC_EMBEDDED_SIGNATURE     = 0xfade0cc0, /* embedded form of signature data */
    CSMAGIC_EMBEDDED_SIGNATURE_OLD = 0xfade0b02, /* XXX */
    CSMAGIC_EMBEDDED_ENTITLEMENTS  = 0xfade7171, /* embedded entitlements */
    CSMAGIC_DETACHED_SIGNATURE     = 0xfade0cc1, /* multi-arch collection of embedded signatures */
    CSMAGIC_BLOBWRAPPER            = 0xfade0b01, /* CMS Signature, among other things */

    CSMAGIC_BYTE = 0xfa, /* shared first byte */

    CS_SUPPORTSSCATTER     = 0x20100,
    CS_SUPPORTSTEAMID      = 0x20200,
    CS_SUPPORTSCODELIMIT64 = 0x20300,
    CS_SUPPORTSEXECSEG     = 0x20400,
    CS_SUPPORTSRUNTIME     = 0x20500,
    CS_SUPPORTSLINKAGE     = 0x20600,

    CSSLOT_CODEDIRECTORY = 0, /* slot index for CodeDirectory */
    CSSLOT_INFOSLOT      = 1,
    CSSLOT_REQUIREMENTS  = 2,
    CSSLOT_RESOURCEDIR   = 3,
    CSSLOT_APPLICATION   = 4,
    CSSLOT_ENTITLEMENTS  = 5,

    CSSLOT_ALTERNATE_CODEDIRECTORIES     = 0x1000, /* first alternate CodeDirectory, if any */
    CSSLOT_ALTERNATE_CODEDIRECTORY_MAX   = 5,      /* max number of alternate CD slots */
    CSSLOT_ALTERNATE_CODEDIRECTORY_LIMIT = CSSLOT_ALTERNATE_CODEDIRECTORIES + CSSLOT_ALTERNATE_CODEDIRECTORY_MAX, /* one past the last */

    CSSLOT_SIGNATURESLOT      = 0x10000, /* CMS Signature */
    CSSLOT_IDENTIFICATIONSLOT = 0x10001,
    CSSLOT_TICKETSLOT         = 0x10002,

    CSTYPE_INDEX_REQUIREMENTS = 0x00000002, /* compat with amfi */
    CSTYPE_INDEX_ENTITLEMENTS = 0x00000005, /* compat with amfi */

    CS_HASHTYPE_NO_HASH          = 0,
    CS_HASHTYPE_SHA1             = 1,
    CS_HASHTYPE_SHA256           = 2,
    CS_HASHTYPE_SHA256_TRUNCATED = 3,
    CS_HASHTYPE_SHA384           = 4,
    CS_HASHTYPE_SHA512           = 5,

    CS_SHA1_LEN             = 20,
    CS_SHA256_LEN           = 32,
    CS_SHA256_TRUNCATED_LEN = 20,

    CS_CDHASH_LEN    = 20, /* always - larger hashes are truncated */
    CS_HASH_MAX_SIZE = 48, /* max size of the hash we'll support */

    /* Currently only to support Legacy VPN plugins, and Mac App Store but intended to replace all the various platform code, dev code etc.
       bits.*/
    CS_SIGNER_TYPE_UNKNOWN       = 0,
    CS_SIGNER_TYPE_LEGACYVPN     = 5,
    CS_SIGNER_TYPE_MAC_APP_STORE = 6,

    CS_SUPPL_SIGNER_TYPE_UNKNOWN    = 0,
    CS_SUPPL_SIGNER_TYPE_TRUSTCACHE = 7,
    CS_SUPPL_SIGNER_TYPE_LOCAL      = 8,
};

/* Structure of an embedded-signature SuperBlob */
struct CS_BlobIndex
{
    CodeSignMagic type; /* type of entry */
    uint32_t offset;    /* offset of entry */
};

struct CS_SuperBlob
{
    CodeSignMagic magic; /* magic number */
    uint32_t length;     /* total length of SuperBlob */
    uint32_t count;      /* number of index entries following */
    // CS_BlobIndex index[0]; /* (count) entries */
    /* followed by Blobs in no particular order as indicated by offsets in index */
};

/* C form of a CodeDirectory. */
struct CS_CodeDirectory
{
    CodeSignMagic magic;    // magic number (CSMAGIC_CODEDIRECTORY) */
    uint32_t length;        // total length of CodeDirectory blob
    uint32_t version;       // compatibility version
    uint32_t flags;         // setup and mode flags
    uint32_t hashOffset;    // offset of hash slot element at index zero
    uint32_t identOffset;   // offset of identifier string
    uint32_t nSpecialSlots; // number of special hash slots
    uint32_t nCodeSlots;    // number of ordinary (code) hash slots
    uint32_t codeLimit;     // limit to main image signature range
    uint8_t hashSize;       // size of each hash in bytes
    uint8_t hashType;       // type of hash (cdHashType* constants)
    PlatformType platform;  // platform identifier; zero if not platform binary
    uint8_t pageSize;       // log2(page size in bytes); 0 => infinite
    uint32_t spare2;        // unused (must be zero)
    uint32_t scatterOffset; /* Version 0x20100 -> offset of optional scatter vector */
    uint32_t teamOffset;    /* Version 0x20200 -> offset of optional team identifier */
    uint32_t spare3;        /* Version 0x20300 -> unused (must be zero) */
    uint64_t codeLimit64;   /* Version 0x20300 -> limit to main image signature range, 64 bits */
    uint64_t execSegBase;   /* Version 0x20400 -> offset of executable segment */
    uint64_t execSegLimit;  /* Version 0x20400 -> limit of executable segment */
    uint64_t execSegFlags;  /* Version 0x20400 -> executable segment flags */
    /* followed by dynamic content as located by offset fields above */
};

struct CS_Blob
{
    CodeSignMagic magic; // magic number
    uint32_t length;     // total length of blob
};

struct CS_GenericBlob
{
    CodeSignMagic magic; /* magic number */
    uint32_t length;     /* total length of blob */
    // char data[];
};

struct CS_RequirementsBlob
{
    CodeSignMagic magic; // magic number
    uint32_t length;     // total length of blob
    uint32_t data;       // zero for dyld shared cache
};

enum class CS_RequirementType : uint32_t
{
    Host       = 1, /* what hosts may run us */
    Guest      = 2, /* what guests we may run */
    Designated = 3, /* designated requirement */
    Library    = 4, /* what libraries we may link against */
    Plugin     = 5  /* what plug-ins we may load */
};

struct CS_Requirement
{
    CS_RequirementType type; // type of entry
    uint32_t offset;         // offset of entry
};

struct CS_Scatter
{
    uint32_t count;        // number of pages; zero for sentinel (only)
    uint32_t base;         // first page number
    uint64_t targetOffset; // byte offset in target
    uint64_t spare;        // reserved (must be zero)
};

struct version_min_command
{
    LoadCommandType cmd; // LC_VERSION_MIN_MACOSX or
                         // LC_VERSION_MIN_IPHONEOS
    uint32_t cmdsize;    // sizeof(struct version_min_command)
    uint32_t version;    // X.Y.Z is encoded in nibbles xxxx.yy.zz
    uint32_t sdk;        // X.Y.Z is encoded in nibbles xxxx.yy.zz
};

constexpr auto CC_SHA1_DIGEST_LENGTH = 20U; /* digest length in bytes */
typedef uint32_t CC_LONG;                   /* 32 bit unsigned integer */

typedef struct
{
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ss;
    uint32_t eflags;
    uint32_t eip;
    uint32_t cs;
    uint32_t ds;
    uint32_t es;
    uint32_t fs;
    uint32_t gs;
} i386_thread_state_t;

struct x86_thread_state64_t
{
    uint64_t rax;
    uint64_t rbx;
    uint64_t rcx;
    uint64_t rdx;
    uint64_t rdi;
    uint64_t rsi;
    uint64_t rbp;
    uint64_t rsp;
    uint64_t r8;
    uint64_t r9;
    uint64_t r10;
    uint64_t r11;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;
    uint64_t rip;
    uint64_t rflags;
    uint64_t cs;
    uint64_t fs;
    uint64_t gs;
};

typedef struct
{
    uint32_t srr0; /* Instruction address register (PC) */
    uint32_t srr1; /* Machine state register (supervisor) */
    uint32_t r[32];

    uint32_t cr;  /* Condition register */
    uint32_t xer; /* User's integer exception register */
    uint32_t lr;  /* Link register */
    uint32_t ctr; /* Count register */
    uint32_t mq;  /* MQ register (601 only) */

    uint32_t vrsave; /* Vector Save Register */
} ppc_thread_state_t;

typedef struct
{
    uint64_t srr0, srr1;
    uint64_t r[32];
    uint32_t cr;
    uint64_t xer, lr, ctr;
    uint32_t vrsave;
} ppc_thread_state64_t;
} // namespace GView::Type::MachO::MAC
