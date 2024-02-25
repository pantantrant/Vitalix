#ifndef __EFI_H
#define __EFI_H

#endif

#ifndef __COMMON_H
#define __COMMON_H

#define IN
#define OUT
#define OPTIONAL
#define CONST
#define EFIAPI

#define TRUE 1
#define FALSE 0
#define NULL 0

#define EFI_SUCCESS 0

#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_NOTIFY 16
#define TPL_HIGH_LEVEL 31

typedef void VOID;
typedef unsigned char BOOLEAN;
typedef signed char INT8;
typedef unsigned char UINT8;
typedef short int INT16;
typedef unsigned short int UINT16;
typedef int INT32;
typedef unsigned int UINT32;
typedef long int INT64;
typedef unsigned long int UINT64;
typedef long long int INT128;
typedef unsigned long long int UINT128;
typedef INT64 INTN;
typedef UINT64 UINTN;

typedef UINT16 CHAR16;

typedef UINTN EFI_STATUS;
typedef UINTN EFI_TPL;
typedef VOID* EFI_HANDLE;
typedef VOID* EFI_EVENT;

struct _EFI_TABLE_HEADER
{
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
};

typedef struct _EFI_TABLE_HEADER EFI_TABLE_HEADER;

#endif

#ifndef __DEVICE_PATH_H
#define __DEVICE_PATH_H

#define EFI_DEVICE_PATH_PROTOCOL_GUID {0x09576e91, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}

struct _EFI_DEVICE_PATH_PROTOCOL
{
    UINT8 Type;
    UINT8 SubType;
    UINT8 Length[2];
};

typedef struct _EFI_DEVICE_PATH_PROTOCOL EFI_DEVICE_PATH_PROTOCOL;

#endif

#ifndef __SIMPLE_TEXT_INPUT_H
#define __SIMPLE_TEXT_INPUT_H

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID {0x387477c1, 0x69c7, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}

struct _EFI_INPUT_KEY
{
    UINT16 ScanCode;
    UINT16 UnicodeChar;
};

typedef struct _EFI_INPUT_KEY EFI_INPUT_KEY;
typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_INPUT_RESET)(IN EFI_SIMPLE_TEXT_INPUT_PROTOCOL* This, IN BOOLEAN ExtendedVerification);
typedef EFI_STATUS (*EFI_INPUT_READ_KEY)(EFI_SIMPLE_TEXT_INPUT_PROTOCOL* This, EFI_INPUT_KEY* Key);

struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_INPUT_RESET Reset;
    EFI_INPUT_READ_KEY ReadKeyStroke;
    EFI_EVENT WaitForKey;
};

#endif

#ifndef __SIMPLE_TEXT_OUTPUT_H
#define __SIMPLE_TEXT_OUTPUT_H

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID {0x387477c2, 0x69c7, 0x11d2, {0x82, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}

struct _SIMPLE_TEXT_OUTPUT_MODE
{
    INT32 MaxMode;
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumn;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
};

typedef struct _SIMPLE_TEXT_OUTPUT_MODE SIMPLE_TEXT_OUTPUT_MODE;
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (*EFI_TEXT_RESET)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, BOOLEAN ExtendedVerification);
typedef EFI_STATUS (*EFI_TEXT_STRING)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, CHAR16* String);
typedef EFI_STATUS (*EFI_TEXT_TEST_STRING)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, CHAR16* String);
typedef EFI_STATUS (*EFI_TEXT_QUERY_MODE)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN ModeNumber, UINTN* Columns, UINTN* Rows);
typedef EFI_STATUS (*EFI_TEXT_SET_MODE)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN ModeNumber);
typedef EFI_STATUS (*EFI_TEXT_SET_ATTRIBUTE)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN Attribute);
typedef EFI_STATUS (*EFI_TEXT_CLEAR_SCREEN)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This);
typedef EFI_STATUS (*EFI_TEXT_SET_CURSOR_POSITION)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, UINTN Column, UINTN Row);
typedef EFI_STATUS (*EFI_TEXT_ENABLE_CURSOR)(EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* This, BOOLEAN Visible);

struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
    EFI_TEXT_RESET Reset;
    EFI_TEXT_STRING OutputString;
    EFI_TEXT_TEST_STRING TestString;
    EFI_TEXT_QUERY_MODE QueryMode;
    EFI_TEXT_SET_MODE SetMode;
    EFI_TEXT_SET_ATTRIBUTE SetAttribute;
    EFI_TEXT_CLEAR_SCREEN ClearScreen;
    EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
    EFI_TEXT_ENABLE_CURSOR EnableCursor;
    SIMPLE_TEXT_OUTPUT_MODE* Mode;
};

#ifndef __GUID_H
#define __GUID_H

struct _EFI_GUID
{
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
};

typedef struct _EFI_GUID EFI_GUID;

#endif

#endif

#ifndef __MEMORY_H
#define __MEMORY_H

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

struct _EFI_MEMORY_DESCRIPTOR
{
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
};

typedef struct _EFI_MEMORY_DESCRIPTOR EFI_MEMORY_DESCRIPTOR;

#endif

#ifndef __TIME_H
#define __TIME_H

#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02
#define EFI_UNSPECIFIED_TIMEZONE 0x07ff

struct _EFI_TIME
{
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 PAD2;
};

struct _EFI_TIME_CAPABILITIES
{
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
};

typedef struct _EFI_TIME EFI_TIME;
typedef struct _EFI_TIME_CAPABILITIES EFI_TIME_CAPABILITIES;

#endif

#ifndef __BOOT_SERVICES_H
#define __BOOT_SERVICES_H

enum _EFI_TIMER_DELAY
{
    TimerCancel,
    TimerPeriodic,
    TimerRelative,
};

enum _EFI_ALLOCATE_TYPE
{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType,
};

enum _EFI_INTERFACE_TYPE
{
    EFI_NATIVE_INTERFACE,
};

enum _EFI_LOCATE_SEARCH_TYPE
{
    AllHandles,
    ByRegisterNotify,
    ByProtocol,
};

struct _EFI_OPEN_PROTOCOL_INFORMATION_ENTRY
{
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
};

typedef enum _EFI_TIMER_DELAY EFI_TIMER_DELAY;
typedef enum _EFI_ALLOCATE_TYPE EFI_ALLOCATE_TYPE;
typedef enum _EFI_INTERFACE_TYPE EFI_INTERFACE_TYPE;
typedef enum _EFI_LOCATE_SEARCH_TYPE EFI_LOCATE_SEARCH_TYPE;
typedef struct _EFI_OPEN_PROTOCOL_INFORMATION_ENTRY EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;
typedef struct _EFI_BOOT_SERVICES EFI_BOOT_SERVICES;

typedef VOID (*EFI_EVENT_NOTIFY)(EFI_EVENT Event, VOID* Context);

typedef EFI_STATUS (*EFI_RAISE_TPL)(EFI_TPL NewTpl);
typedef EFI_STATUS (*EFI_RESTORE_TPL)(EFI_TPL OldTpl);
typedef EFI_STATUS (*EFI_ALLOCATE_PAGES)(EFI_ALLOCATE_TYPE Type, UINTN MemoryType, UINTN Pages, EFI_PHYSICAL_ADDRESS* Memory);
typedef EFI_STATUS (*EFI_FREE_PAGES)(EFI_PHYSICAL_ADDRESS Memory, UINTN Pages);
typedef EFI_STATUS (*EFI_GET_MEMORY_MAP)(UINTN* MemoryMapSize, EFI_MEMORY_DESCRIPTOR* MemoryMap, UINTN* MapKey, UINTN* DescriptorSize, UINT32* DescriptorVersion);
typedef EFI_STATUS (*EFI_ALLOCATE_POOL)(UINTN PoolType, UINTN Size, VOID** Buffer);
typedef EFI_STATUS (*EFI_FREE_POOL)(VOID* Buffer);
typedef EFI_STATUS (*EFI_CREATE_EVENT)(UINT32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, VOID* NotifyContext, EFI_GUID* EventGroup, EFI_EVENT* Event);
typedef EFI_STATUS (*EFI_SET_TIMER)(EFI_EVENT Event, EFI_TIMER_DELAY Type, UINT64 TriggerTime);
typedef EFI_STATUS (*EFI_WAIT_FOR_EVENT)(UINTN NumberOfEvents, EFI_EVENT* Event, UINTN* Index);
typedef EFI_STATUS (*EFI_SIGNAL_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_CLOSE_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_CHECK_EVENT)(EFI_EVENT Event);
typedef EFI_STATUS (*EFI_INSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE* Handle, EFI_GUID* Protocol, EFI_INTERFACE_TYPE InterfaceType, VOID* Interface);
typedef EFI_STATUS (*EFI_REINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE Handle, EFI_GUID* Protocol, VOID* OldInterface, VOID* NewInterface);
typedef EFI_STATUS (*EFI_UNINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE Handle, EFI_GUID* Protocol, VOID* Interface);
typedef EFI_STATUS (*EFI_HANDLE_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID* Protocol, VOID** Interface);
typedef EFI_STATUS (*EFI_REGISTER_PROTOCOL_NOTIFY)(EFI_GUID* Protocol, EFI_EVENT Event, VOID** Registration);
typedef EFI_STATUS (*EFI_LOCATE_HANDLE)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID* Protocol, VOID* SearchKey, UINTN* BufferSize, EFI_HANDLE* Buffer);
typedef EFI_STATUS (*EFI_LOCATE_DEVICE_PATH)(EFI_GUID* Protocol, EFI_DEVICE_PATH_PROTOCOL** DevicePath, EFI_HANDLE* Device);
typedef EFI_STATUS (*EFI_INSTALL_CONFIGURATION_TABLE)(EFI_GUID* Guid, VOID* Table);
typedef EFI_STATUS (*EFI_IMAGE_LOAD)(BOOLEAN BootPolicy, EFI_HANDLE ParentImageHandle, EFI_DEVICE_PATH_PROTOCOL* DevicePath, VOID* SourceBuffer, UINTN SourceSize, EFI_HANDLE* ImageHandle);
typedef EFI_STATUS (*EFI_IMAGE_START)(EFI_HANDLE ImageHandle, UINTN* ExitDataSize, CHAR16** ExitData);
typedef EFI_STATUS (*EFI_EXIT)(EFI_HANDLE ImageHandle, EFI_STATUS ExitStatus, UINTN ExitDataSize, CHAR16* ExitData);
typedef EFI_STATUS (*EFI_IMAGE_UNLOAD)(EFI_HANDLE ImageHandle);
typedef EFI_STATUS (*EFI_EXIT_BOOT_SERVICES)(EFI_HANDLE ImageHandle, UINTN MapKey);
typedef EFI_STATUS (*EFI_GET_NEXT_MONOTONIC_COUNT)(UINT64* Count);
typedef EFI_STATUS (*EFI_STALL)(UINTN Microseconds);
typedef EFI_STATUS (*EFI_SET_WATCHDOG_TIMER)(UINTN Timeout, UINT64 WatchdogCode, UINTN DataSize, CHAR16* WatchdogData);
typedef EFI_STATUS (*EFI_CONNECT_CONTROLLER)(EFI_HANDLE ControllerHandle, EFI_HANDLE* DriverImageHandle, EFI_DEVICE_PATH_PROTOCOL* RemainingDevicePath, BOOLEAN Recursive);
typedef EFI_STATUS (*EFI_DISCONNECT_CONTROLLER)(EFI_HANDLE ControllerHandle, EFI_HANDLE DriverImageHandle, EFI_HANDLE ChildHandle);
typedef EFI_STATUS (*EFI_OPEN_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID* Protocol, void** Interface, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle, UINT32 Attributes);
typedef EFI_STATUS (*EFI_CLOSE_PROTOCOL)(EFI_HANDLE Handle, EFI_GUID* Protocol, EFI_HANDLE AgentHandle, EFI_HANDLE ControllerHandle);
typedef EFI_STATUS (*EFI_OPEN_PROTOCOL_INFORMATION)(EFI_HANDLE Handle, EFI_GUID* Protocol, EFI_OPEN_PROTOCOL_INFORMATION_ENTRY** EntryBuffer, UINTN* EntryCount);
typedef EFI_STATUS (*EFI_PROTOCOLS_PER_HANDLE)(EFI_HANDLE Handle, EFI_GUID*** ProtocolBuffer, UINTN* ProtocolBufferCount);
typedef EFI_STATUS (*EFI_LOCATE_HANDLE_BUFFER)(EFI_LOCATE_SEARCH_TYPE SearchType, EFI_GUID* Protocol, VOID* SearchKey, UINTN* NoHandles, EFI_HANDLE** Buffer);
typedef EFI_STATUS (*EFI_LOCATE_PROTOCOL)(EFI_GUID* Protocol, VOID* Registration, VOID** Interface);
typedef EFI_STATUS (*EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE* Handle, ...);
typedef EFI_STATUS (*EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE* Handle, ...);
typedef EFI_STATUS (*EFI_CALCULATE_CRC32)(VOID* Data, UINTN DataSize, UINT32* Crc32);
typedef EFI_STATUS (*EFI_COPY_MEM)(VOID* Destination, VOID* Source, UINTN Length);
typedef EFI_STATUS (*EFI_SET_MEM)(VOID* Buffer, UINTN Size, UINT8 Value);
typedef EFI_STATUS (*EFI_CREATE_EVENT_EX)(UINT32 Type, EFI_TPL NotifyTpl, EFI_EVENT_NOTIFY NotifyFunction, VOID* NotifyContext, EFI_GUID* EventGroup, EFI_EVENT* Event);

struct _EFI_BOOT_SERVICES
{
    EFI_TABLE_HEADER Hdr;
    EFI_RAISE_TPL RaiseTPL;
    EFI_RESTORE_TPL RestoreTPL;
    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;
    EFI_CREATE_EVENT CreateEvent;
    EFI_SET_TIMER SetTimer;
    EFI_WAIT_FOR_EVENT WaitForEvent;
    EFI_SIGNAL_EVENT SignalEvent;
    EFI_CLOSE_EVENT CloseEvent;
    EFI_CHECK_EVENT CheckEvent;
    EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL HandleProtocol;
    VOID* Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
    EFI_LOCATE_HANDLE LocateHandle;
    EFI_LOCATE_DEVICE_PATH LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;
    EFI_IMAGE_LOAD LoadImage;
    EFI_IMAGE_START StartImage;
    EFI_EXIT Exit;
    EFI_IMAGE_UNLOAD UnloadImage;
    EFI_EXIT_BOOT_SERVICES ExitBootServices;
    EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
    EFI_STALL Stall;
    EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;
    EFI_CONNECT_CONTROLLER ConnectController;
    EFI_DISCONNECT_CONTROLLER DisconnectController;
    EFI_OPEN_PROTOCOL OpenProtocol;
    EFI_CLOSE_PROTOCOL CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;
    EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;
    EFI_CALCULATE_CRC32 CalculateCrc32;
    EFI_COPY_MEM CopyMem;
    EFI_SET_MEM SetMem;
    EFI_CREATE_EVENT_EX CreateEventEx;
};

#endif

#ifndef __RUNTIME_SERVICES_H
#define __RUNTIME_SERVICES_H

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

enum _EFI_RESET_TYPE
{
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific,
};

union _EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS
{
    EFI_PHYSICAL_ADDRESS DataBlock;
    EFI_PHYSICAL_ADDRESS ContinuationPointer;
};

typedef union _EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS;

struct _EFI_CAPSULE_BLOCK_DESCRIPTOR
{
    UINT64 Length;
    EFI_CAPSULE_BLOCK_DESCRIPTOR_ADDRESS Union;
};

struct _EFI_CAPSULE_HEADER
{
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
};

typedef enum _EFI_RESET_TYPE EFI_RESET_TYPE;
typedef struct _EFI_CAPSULE_BLOCK_DESCRIPTOR EFI_CAPSULE_BLOCK_DESCRIPTOR;
typedef struct _EFI_CAPSULE_HEADER EFI_CAPSULE_HEADER;

typedef EFI_STATUS (*EFI_GET_TIME)(EFI_TIME* Time, EFI_TIME_CAPABILITIES* Capabilities);
typedef EFI_STATUS (*EFI_SET_TIME)(EFI_TIME* Time);
typedef EFI_STATUS (*EFI_GET_WAKEUP_TIME)(BOOLEAN* Enabled, BOOLEAN* Pending, EFI_TIME* Time);
typedef EFI_STATUS (*EFI_SET_WAKEUP_TIME)(BOOLEAN Enable, EFI_TIME* Time);
typedef EFI_STATUS (*EFI_SET_VIRTUAL_ADDRESS_MAP)(UINTN MemoryMapSize, UINTN DescriptorSize, UINT32 DescriptorVersion, EFI_MEMORY_DESCRIPTOR* VirtualMap);
typedef EFI_STATUS (*EFI_CONVERT_POINTER)(UINTN DebugDisposition, VOID** Address);
typedef EFI_STATUS (*EFI_GET_VARIABLE)(CHAR16* VariableName, EFI_GUID* VendorGuid, UINT32* Attributes, UINTN* DataSize, VOID* Data);
typedef EFI_STATUS (*EFI_GET_NEXT_VARIABLE_NAME)(UINTN* VariableNameSize, CHAR16* VariableName, EFI_GUID* VendorGuid);
typedef EFI_STATUS (*EFI_SET_VARIABLE)(CHAR16* VariableName, EFI_GUID* VendorGuid, UINT32 Attributes, UINTN DataSize, VOID* Data);
typedef EFI_STATUS (*EFI_GET_NEXT_HIGH_MONO_COUNT)(UINT32* HighCount);
typedef EFI_STATUS (*EFI_RESET_SYSTEM)(EFI_RESET_TYPE ResetType, EFI_STATUS ResetStatus, UINTN DataSize, VOID* ResetData);
typedef EFI_STATUS (*EFI_UPDATE_CAPSULE)(EFI_CAPSULE_HEADER** CapsuleHeaderArray, UINTN CapsuleCount, EFI_PHYSICAL_ADDRESS ScatterGatherList);
typedef EFI_STATUS (*EFI_QUERY_CAPSULE_CAPABILITIES)(EFI_CAPSULE_HEADER** CapsuleHeaderArray, UINTN CapsuleCount, UINT64* MaximumCapsuleSize, EFI_RESET_TYPE* ResetType);
typedef EFI_STATUS (*EFI_QUERY_VARIABLE_INFO)(UINT32 Attributes, UINT64* MaximumVariableStorageSize, UINT64* RemainingVariableStorageSize, UINT64* MaximumVariableSize);

struct _EFI_RUNTIME_SERVICES
{
    EFI_TABLE_HEADER Hdr;
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;
    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;
    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
};

typedef struct _EFI_RUNTIME_SERVICES EFI_RUNTIME_SERVICES;

#endif

#ifndef __CONFIGURATION_TABLE_H
#define __CONFIGURATION_TABLE_H

struct _EFI_CONFIGURATION_TABLE
{
    EFI_GUID VendorGuid;
    VOID* VendorTable;
};

typedef struct _EFI_CONFIGURATION_TABLE EFI_CONFIGURATION_TABLE;

#endif

#ifndef __SYSTEM_TABLE_H
#define __SYSTEM_TABLE_H

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249

#define EFI_2_80_SYSTEM_TABLE_REVISION ((2<<16) | (80))
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))

#define EFI_SYSTEM_TABLE_REVISION EFI_2_8_SYSTEM_TABLE_REVISION
#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION

struct _EFI_SYSTEM_TABLE
{
    EFI_TABLE_HEADER Hdr;
    CHAR16* FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL* ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* StdErr;
    EFI_RUNTIME_SERVICES* RuntimeServices;
    EFI_BOOT_SERVICES* BootServices;
    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE* ConfigurationTable;
};

typedef struct _EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

#endif

unsigned char ret;

unsigned long long io_read_8(unsigned short port) {
	__asm__ volatile ("inb %w1, %b0" : "=a" (ret) : "Nd" (port));
	return ret;
}

void io_write_8(unsigned short port, unsigned char val) {
	__asm__ volatile ("outb %b0, %w1" : : "a" (val), "Nd" (port));
}

#define SERIAL_COM1_BASE 0x3F8
#define SERIAL_MAX_BAUD_RATE 115200
#define SERIAL_BAUD_RATE 38400
#define SERIAL_LINE_COMMAND_PORT(base) (base + 3)
#define SERIAL_LINE_ENABLE_DLAB 0x80
#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base + 2)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)

static void serial_port_configure_baud_rate(unsigned short com, unsigned short divisor) {
	io_write_8(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
	io_write_8(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
	io_write_8(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

static void serial_port_configure_line(unsigned short com) {
	io_write_8(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

static void serial_port_configure_buffers(unsigned short com) {
	io_write_8(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
}

static void serial_port_configure_modem(unsigned short com) {
	io_write_8(SERIAL_MODEM_COMMAND_PORT(com), 0x0B);
}

void serial_port_init() {
	serial_port_configure_baud_rate(SERIAL_COM1_BASE, SERIAL_MAX_BAUD_RATE / SERIAL_BAUD_RATE);
	serial_port_configure_line(SERIAL_COM1_BASE);
	serial_port_configure_buffers(SERIAL_COM1_BASE);
	serial_port_configure_modem(SERIAL_COM1_BASE);
}

void serial_port_putchar(const char c) {
	io_write_8(SERIAL_DATA_PORT(SERIAL_COM1_BASE), c);
}

char getkey = 0;

char serial_port_getkey() {
	short getkey = 0;
	while (getkey == 0) {
		getkey = io_read_8(SERIAL_DATA_PORT(SERIAL_COM1_BASE));
	};
	return getkey;
}

EFI_STATUS EFIAPI vitalix_shell_repl(IN EFI_SYSTEM_TABLE* SystemTable) {
	unsigned char i;
	switch (serial_port_getkey()) {
		case 'a':
			serial_port_putchar('a');
			break;
		case 'b':
			serial_port_putchar('b');
			break;
		case 'c':
			serial_port_putchar('c');
			break;
		case 'd':
			serial_port_putchar('d');
			break;
		case 'e':
			serial_port_putchar('e');
			switch (serial_port_getkey()) {
				case 'x':
					serial_port_putchar('x');
					switch (serial_port_getkey()) {
						case 'i':
							serial_port_putchar('i');
							switch (serial_port_getkey()) {
								case 't':
									serial_port_putchar('t');
									switch (serial_port_getkey()) {
										case '\r':
											serial_port_putchar('\n');
											SystemTable->RuntimeServices->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
											break;
										default:
											serial_port_putchar(getkey);
											break;
									}
									break;
								case '\r':
									serial_port_putchar('\r');
									serial_port_putchar('\n');
									serial_port_putchar(' ');
									serial_port_putchar('#');
									serial_port_putchar(' ');
									break;
								default:
									serial_port_putchar(getkey);
									break;
							}
							break;
						case '\r':
							serial_port_putchar('\r');
							serial_port_putchar('\n');
							serial_port_putchar(' ');
							serial_port_putchar('#');
							serial_port_putchar(' ');
							break;
						default:
							serial_port_putchar(getkey);
							break;
					}
					break;
				case '\r':
					serial_port_putchar('\r');
					serial_port_putchar('\n');
					serial_port_putchar(' ');
					serial_port_putchar('#');
					serial_port_putchar(' ');
					break;
				default:
					serial_port_putchar(getkey);
					break;
			}
			break;
		case 'f':
			serial_port_putchar('f');
			break;
		case 'g':
			serial_port_putchar('g');
			break;
		case 'h':
			serial_port_putchar('h');
			break;
		case 'i':
			serial_port_putchar('i');
			break;
		case 'j':
			serial_port_putchar('j');
			break;
		case 'k':
			serial_port_putchar('k');
			break;
		case 'l':
			serial_port_putchar('l');
			break;
		case 'm':
			serial_port_putchar('m');
			break;
		case 'n':
			serial_port_putchar('n');
			break;
		case 'o':
			serial_port_putchar('o');
			break;
		case 'p':
			serial_port_putchar('p');
			break;
		case 'q':
			serial_port_putchar('q');
			break;
		case 'r':
			serial_port_putchar('r');
			break;
		case 's':
			serial_port_putchar('s');
			break;
		case 't':
			serial_port_putchar('t');
			break;
		case 'u':
			serial_port_putchar('u');
			break;
		case 'v':
			serial_port_putchar('v');
			break;
		case 'w':
			serial_port_putchar('w');
			break;
		case 'x':
			serial_port_putchar('x');
			break;
		case 'y':
			serial_port_putchar('y');
			break;
		case 'z':
			serial_port_putchar('z');
			break;
		case '\r':
			serial_port_putchar('\r');
			serial_port_putchar('\n');
			serial_port_putchar(' ');
			serial_port_putchar('#');
			serial_port_putchar(' ');
			break;
		case '\b':
			serial_port_putchar('\r');
			for (i=0;i<80;i=i+1) {
				serial_port_putchar(' ');
			};
			serial_port_putchar('\r');
			serial_port_putchar(' ');
			serial_port_putchar('#');
			serial_port_putchar(' ');
			break;
		case ' ':
			serial_port_putchar(' ');
			break;
		case '0':
			serial_port_putchar('0');
			break;
		case '1':
			serial_port_putchar('1');
			break;
		case '2':
			serial_port_putchar('2');
			break;
		case '3':
			serial_port_putchar('3');
			break;
		case '4':
			serial_port_putchar('4');
			break;
		case '5':
			serial_port_putchar('5');
			break;
		case '6':
			serial_port_putchar('6');
			break;
		case '7':
			serial_port_putchar('7');
			break;
		case '8':
			serial_port_putchar('8');
			break;
		case '9':
			serial_port_putchar('9');
			break;
		case 'A':
			serial_port_putchar('A');
			break;
		case 'B':
			serial_port_putchar('B');
			break;
		case 'C':
			serial_port_putchar('C');
			break;
		case 'D':
			serial_port_putchar('D');
			break;
		case 'E':
			serial_port_putchar('E');
			break;
		case 'F':
			serial_port_putchar('F');
			break;
		case 'G':
			serial_port_putchar('G');
			break;
		case 'H':
			serial_port_putchar('H');
			break;
		case 'I':
			serial_port_putchar('I');
			break;
		case 'J':
			serial_port_putchar('J');
			break;
		case 'K':
			serial_port_putchar('K');
			break;
		case 'L':
			serial_port_putchar('L');
			break;
		case 'M':
			serial_port_putchar('M');
			break;
		case 'N':
			serial_port_putchar('N');
			break;
		case 'O':
			serial_port_putchar('O');
			break;
		case 'P':
			serial_port_putchar('P');
			break;
		case 'Q':
			serial_port_putchar('Q');
			break;
		case 'R':
			serial_port_putchar('R');
			break;
		case 'S':
			serial_port_putchar('S');
			break;
		case 'T':
			serial_port_putchar('T');
			break;
		case 'U':
			serial_port_putchar('U');
			break;
		case 'V':
			serial_port_putchar('V');
			break;
		case 'W':
			serial_port_putchar('W');
			break;
		case 'X':
			serial_port_putchar('X');
			break;
		case 'Y':
			serial_port_putchar('Y');
			break;
		case 'Z':
			serial_port_putchar('Z');
			break;
	}
	/*
	Now that my os which is just for me can do serial input and serial output and boot
	from UEFI, I want it to go into the vitalix shell. I want the vitalix shell to have
	the following features:
		* All lowercase program names.
		* Programs can yield to the vitalix shell repl with goto vitalix_shell_repl;
		* The user can exit to the UEFI boot menu with exit.
		* No directory traversal.
		* No path variable, all the programs are inside of vitalix.c
	Programs that I want to add inside of vitalix.c:
		My statically linked simple text editor and its source code.
		My statically linked program called "redeploy" and its source code,
		which would compile vitalix.c into a fat12 /EFI/BOOT/BOOTX64.EFI file and burn that to a connected BD RE disk.
		My statically linked compiler and its source code.
	*/
}

EFI_HANDLE _ImageHandle;
EFI_SYSTEM_TABLE _SystemTable;

EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE* SystemTable) {
	SystemTable->BootServices->SetWatchdogTimer(0, 0, 0, NULL);
	serial_port_init();
	serial_port_putchar('\n');
	serial_port_putchar(' ');
	serial_port_putchar('#');
	serial_port_putchar(' ');
	while (1) {
		vitalix_shell_repl(SystemTable);
	};
}
