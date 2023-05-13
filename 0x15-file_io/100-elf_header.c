#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * is_elf_file - confirms if file is an ELF file.
 * @out: A pointer to an array containing the ELF magic numbers.
 *
 * Return: 0 success
 */
int is_elf_file(unsigned char *out)
{
	int x;

	for (x = 0; x < 4; x++)
	{
		if (out[x] != 127 &&
		    out[x] != 69 &&
		    out[x] != 76 &&
		    out[x] != 70)
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
	return (0);
}

/**
 * magic - Prints the 16 magic numbers of an ELF header file.
 * @out: returns alpha numeric ELF magic numbers.
 *
 * Return: 0 success
 */
int magic(unsigned char *out)
{
	int y;

	printf("  Magic:   ");

	for (y = 0; y < EI_NIDENT; y++)
	{
		printf("%02x", out[y]);

		if (y == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
	return (0);
}

/**
 * class - Prints the class of ELF header file.
 * @out: returns the class of the ELF file.
 *
 * Return: 0 success
 */
int class(unsigned char *out)
{
	printf("  Class:                             ");

	switch (out[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", out[EI_CLASS]);
	}
	return (0);
}

/**
 * data - outputs the data related to ELF header file.
 * @out: A pointer to an array containing data on ELF file.
 *
 * Return: 0 success
 */
int data(unsigned char *out)
{
	printf("  Data:                              ");

	switch (out[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", out[EI_CLASS]);
	}
	return (0);
}

/**
 * version - returns the version of an ELF header file.
 * @out: A pointer to an array containing the ELF file version.
 *
 * Return: 0 success
 */
int version(unsigned char *out)
{
	printf("  Version:                           %d",
	       out[EI_VERSION]);

	switch (out[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
	return (0);
}

/**
 * osabi - output the OS/ABI of an ELF header file.
 * @out: A pointer to an array containing the ELF file version.
 *
 * Return: 0 success
 */
int osabi(unsigned char *out)
{
	printf("  OS/ABI:                            ");

	switch (out[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", out[EI_OSABI]);
	}
	return (0);
}

/**
 * abi - outcome the ABI version of an ELF header file.
 * @out:  pointer to an array containing the ELF ABI version.
 *
 * Return: 0 success
 */
int abi(unsigned char *out)
{
	printf("  ABI Version:                       %d\n",
	       out[EI_ABIVERSION]);
	return (0);
}

/**
 * type - outputs the type of an ELF header file .
 * @ELF_type: represents the ELF file type.
 * @out: A pointer to an array containing the ELF class.
 *
 * Return: 0 success
 */
int type(unsigned int ELF_type, unsigned char *out)
{
	if (out[EI_DATA] == ELFDATA2MSB)
		ELF_type >>= 8;

	printf("  Type:                              ");

	switch (ELF_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", ELF_type);
	}
	return (0);
}

/**
 * entry - outputs the entry point of the ELF header file.
 * @ELF_entry: The address of the ELF entry point.
 * @out: pointer to an array containing the ELF header class.
 *
 * Return: 0 success
 */
int entry(unsigned long int ELF_entry, unsigned char *out)
{
	printf("  Entry point address:               ");

	if (out[EI_DATA] == ELFDATA2MSB)
	{
		ELF_entry = ((ELF_entry << 8) & 0xFF00FF00) |
			  ((ELF_entry >> 8) & 0xFF00FF);
		ELF_entry = (ELF_entry << 16) | (ELF_entry >> 16);
	}

	if (out[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)ELF_entry);

	else
		printf("%#lx\n", ELF_entry);
	return (0);
}

/**
 * elf_TERM - Closes the ELF header file.
 * @elf: file descriptor of ELF header file.
 *
 * Return: 0 success
 */
int elf_TERM(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
	return (0);
}

/**
 * main - outputs details in ELF file
 * @ac: The number of arguments
 * @av: An array of pointers to arguments.
 *
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) ac, char *av[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(av[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_TERM(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		elf_TERM(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
		exit(98);
	}

	is_elf_file(header->e_ident);
	printf("ELF Header:\n");
	magic(header->e_ident);
	class(header->e_ident);
	data(header->e_ident);
	version(header->e_ident);
	osabi(header->e_ident);
	abi(header->e_ident);
	type(header->e_type, header->e_ident);
	entry(header->e_entry, header->e_ident);

	free(header);
	elf_TERM(o);
	return (0);
}
