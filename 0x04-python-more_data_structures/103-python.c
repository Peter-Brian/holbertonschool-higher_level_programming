#include <Python.h>

void print_python_bytes(PyObject *p)
{
	int i = 0, bsize = 0;
	char *str;

	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}
	bsize = PyBytes_Size(p);
    printf("[.] bytes object info\n");
	printf("  size: %d\n", bsize);
	str = ((PyBytesObject *)p)->ob_sval;
	printf("  trying string: %s\n", str);
	printf("  first 10 bytes:");

	for (i = 0; (i <= bsize) && (i <= 10); i++)
	{
			printf("  %02hhx", str[i]);
	}
	printf("\n");
}

/**
 * print_python_list_info - prints info about Python lists
 * @p: Python Object
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
void print_python_list(PyObject *p)
{
	long int list_size, alloc_list, i;
	PyObject *item;

	list_size = PyList_Size(p);
	alloc_list = ((PyListObject *)p)->allocated;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", list_size);
	printf("[*] Allocated = %ld\n", alloc_list);
	for (i = 0; i < list_size; i++)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
        if (PyBytes_Check(item))
            print_python_bytes(item);
	}
}
