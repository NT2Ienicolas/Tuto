/*
 * Codec class for SQLite3 encryption codec.
 * (C) 2010 Olivier de Gaalon
 *
 * Distributed under the terms of the Botan license
 */

#ifndef _CODEC_H_
#define _CODEC_H_

#include <string>

using namespace std;

//This is definited in sqlite.h and very unlikely to change
#define SQLITE_MAX_PAGE_SIZE 32768

class Codec
{
public:
    Codec(void *db);
    Codec(const Codec* other, void *db);

	void GenerateKey(const char *Key, int KeyLength);
	void DropKey();

	unsigned char* Encrypt(int page, unsigned char *data, bool useKey);
	void Decrypt(int page, unsigned char *data);

	void SetPageSize(int pageSize) { m_pageSize = pageSize; }

	bool HasKey() { return m_hasKey; }
	void* GetDB() { return m_db; }
	const char* GetAndResetError();
	void AddToLog (const char *szMsg);

private:
	bool m_hasKey;

	char m_Key[50];
	int m_pageSize;
	unsigned char m_page[SQLITE_MAX_PAGE_SIZE];
	void *m_db;
	const char *m_botanErrorMsg;

	void InitializeCodec(void *db);
};

#endif
