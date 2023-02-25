#include "MemoryManager.h"

static void printHex(DWORD addr, const std::string& prefix)
{
	std::cout << prefix << std::hex << addr << std::endl;
}

int main(int argc, char* argv[])
{
	char cBuffer[20] = {};
	MemoryManager memManager;
	memManager.attach_to_process("Fallout3");
	DWORD baseAddress = memManager.get_module_address("Fallout3.exe");
	constexpr DWORD solutionOffset = 0x00E3A1AC;
	constexpr DWORD offsetTwo = 0x19C;

	DWORD solutionIndirectionAddress = memManager.read_memory<DWORD>(baseAddress + solutionOffset);
	DWORD solutionAddress = memManager.read_memory<DWORD>(solutionIndirectionAddress + offsetTwo);

	memManager.read_string_from_memory(solutionAddress, cBuffer, sizeof(cBuffer));
	std::cout << std::endl << std::endl;
	std::cout <<"The solution is: " << cBuffer << std::endl;

	getchar();
	return 0;
}