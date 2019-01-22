
/*************************************************************************
   LAB 1

	Edit this file ONLY!

*************************************************************************/


#include "dns.h"

DNSHandle InitDNS()//�������������
{
	DNSHandle hDNS = Init();
	if ((Hash_Table*)hDNS != NULL)
		return hDNS;
	return INVALID_DNS_HANDLE;
}

void LoadHostsFile(DNSHandle hDNS, const char* hostsFilePath)//������ �����
{
	char hostName[255], ip[15];
	FILE *file = fopen(hostsFilePath, "r");
	while (!feof(file)) {
		fscanf(file, "%s", &ip);
		fscanf(file, "%s", &hostName);
		Insert((Hash_Table*)hDNS, hostName, ip);//������� � ���-�������
	}
	fclose(file);
}

IPADDRESS DnsLookUp(DNSHandle hDNS, const char* hostName)
{
	return Find((Hash_Table*)hDNS, hostName);
}

void ShutdownDNS(DNSHandle hDNS)
{
	Delete((Hash_Table*)hDNS);
}
