/*
 * Codec class for SQLite3 encryption codec.
 * (C) 2010 Olivier de Gaalon
 *
 * Distributed under the terms of the Botan license
 */

#include "codec.h"

Codec::Codec(void *db)
{
	//AddToLog ("Codec::Codec(void *db)");
	InitializeCodec(db);
}

Codec::Codec(const Codec *other, void *db)
{
	//AddToLog ("Codec::Codec(const Codec *other, void *db)");
	//Only used to copy main db key for an attached db
	InitializeCodec(db);
	m_hasKey = other->m_hasKey;
}

void Codec::InitializeCodec(void *db)
{
	m_hasKey  = false;
	m_db = db;
}

void Codec::GenerateKey(const char *Key, int KeyLength)
{
	strncpy(m_Key, (char *)Key, KeyLength);
	m_hasKey = true;
}

void Codec::DropKey()
{
	m_hasKey = false;
}

unsigned char* Codec::Encrypt(int page, unsigned char *data, bool useKey)
{
	/*
	char sLog[1100];
	char sTpo[1000];
	strncpy(sTpo, data, 1000);
	sprintf(sLog, "Codec::Encrypt[%d] => %s", strlen(data), sTpo);
	AddToLog (sLog);
	*/

	char localKey = 1;
	memcpy(m_page, data, m_pageSize);
	try
	{
		for (int i = 0; i < m_pageSize; i++)
		{
			//char cTpo = m_page[i];
			//if (((m_page[i] > 20) || (m_page[i] < 0))
			//					&& ((m_page[i]^m_Key[0] > 20) || (m_page[i]^m_Key[0] < 0)))
				m_page[i] = m_page[i]^m_Key[0];
			//sprintf(sLog, "Codec::Encrypt : %d => %d", cTpo, m_page[i]);
			//AddToLog (sLog);
		}
		/*
		strncpy(sTpo, m_page, 1000);
		sprintf(sLog, "Codec::Encrypt[%d] Result => %s", strlen(m_page), sTpo);
		AddToLog (sLog);
		*/
	}
	catch (...)
	{
		//
	}
	return m_page; //return location of newly ciphered data
}

void Codec::Decrypt(int page, unsigned char *data)
{
	/*
	char sLog[1100];
	char sTpo[1000];
	strncpy(sTpo, data, 999);
	sprintf(sLog, "Codec::Decrypt[%d] => %s", strlen(data), sTpo);
	AddToLog (sLog);
	*/

	char localKey = 1;
	try
	{
		for (int i = 0; i <m_pageSize; i++)
		{
			//char cTpo = data[i];
			//if (((data[i] > 20) || (data[i] < 0))
			//					&& ((data[i]^m_Key[0] > 20) || (data[i]^m_Key[0] < 0)))
				data[i] = data[i]^m_Key[0];
			//sprintf(sLog, "Codec::Decrypt : %d => %d", cTpo, data[i]);
			//AddToLog (sLog);
		}
		/*
		strncpy(sTpo, data, 1000);
		sprintf(sLog, "Codec::Decrypt[%d] Result => %s", strlen(data), sTpo);
		AddToLog (sLog);
		*/
	}
	catch (...)
	{
		//
	}
}


const char* Codec::GetAndResetError()
{
	return "";
}

void Codec::AddToLog (const char *szMsg)
{
	char szFile[80];
	FILE *fp;
	sprintf (szFile, "%s", "Codec.log");
	fp = fopen (szFile, "a+");       // Create or append
	if (fp == NULL)                  // Couldn't open, PUNT!
	  return;

	fprintf (fp, "%s\n", szMsg);
	fclose (fp);

}

#include "codec_c_interface.h"

void* InitializeNewCodec(void *db) {
	return new Codec(db);
}
void* InitializeFromOtherCodec(const void *otherCodec, void *db) {
	return new Codec((Codec*)otherCodec, db);
}

void GenerateKey(void *codec, const char *userPassword, int passwordLength) {
	((Codec*)codec)->GenerateKey(userPassword, passwordLength);
}
void DropKey(void *codec) {
	((Codec*)codec)->DropKey();
}
unsigned char* Encrypt(void *codec, int page, unsigned char *data, Bool useKey) {
	return ((Codec*)codec)->Encrypt(page, data, useKey);
}
void Decrypt(void *codec, int page, unsigned char *data) {
	((Codec*)codec)->Decrypt(page, data);
}
void SetPageSize(void *codec, int pageSize) {
	((Codec*)codec)->SetPageSize(pageSize);
}
Bool HasKey(void *codec) {
	return ((Codec*)codec)->HasKey();
}
void* GetDB(void *codec) {
	return ((Codec*)codec)->GetDB();
}
const char* GetAndResetError(void *codec)
{
	return ((Codec*)codec)->GetAndResetError();
}
void DeleteCodec(void *codec) {
	Codec *deleteThisCodec = (Codec*)codec;
	delete deleteThisCodec;
}


