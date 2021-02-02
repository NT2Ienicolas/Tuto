//---------------------------------------------------------------------------
// TODO :
//		- Fonction de décodage des fichiers archivés
//		- Mode "Query" :
//			Si activé, en réception d'un query, on cherche id dans la base
//			et on répond
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UFMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMain *FMain;
//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormCreate(TObject *Sender)
{
	sgBD->Cells[0][0] = "#";
	sgBD->Cells[1][0] = "Sample ID";
	sgBD->Cells[2][0] = "Patient ID";
	sgBD->Cells[3][0] = "Name";
	sgBD->Cells[4][0] = "Test";

	sgJournal->Cells[0][0] = "D/H";
	sgJournal->Cells[1][0] = "Type";
	sgJournal->Cells[2][0] = "E/R";
	sgJournal->Cells[3][0] = "Archive";

	//Test existence BD
	UnicodeString sPathBD = CheminBD();
	if (!FileExists(sPathBD))
	{
		AnsiString QuerySQL = "";

		QuerySQL = "CREATE TABLE T_Samples " ;
		QuerySQL = QuerySQL + "( ";
		QuerySQL = QuerySQL + "SampleKey integer, ";
		QuerySQL = QuerySQL + "SampleID varchar(15), ";
		QuerySQL = QuerySQL + "PatientID varchar(15), ";
		QuerySQL = QuerySQL + "PName varchar(200), ";
		QuerySQL = QuerySQL + "PFirstN varchar(200), ";
		QuerySQL = QuerySQL + "PMaidenN varchar(200), ";
		QuerySQL = QuerySQL + "PRIMARY KEY ( SampleKey)); ";
		myExecSQL(QuerySQL);

		QuerySQL = "CREATE TABLE T_Tests ";
		QuerySQL = QuerySQL + "( ";
		QuerySQL = QuerySQL + "SampleKey integer, ";
		QuerySQL = QuerySQL + "TestNumber integer, ";
		QuerySQL = QuerySQL + "TestName varchar(15), ";
		QuerySQL = QuerySQL + "Dilution integer, ";
		QuerySQL = QuerySQL + "TestType varchar(2), ";
		QuerySQL = QuerySQL + "SampleType varchar(2), ";
		QuerySQL = QuerySQL + "ST varchar(2), ";
		QuerySQL = QuerySQL + "TubeType varchar(2), ";
		QuerySQL = QuerySQL + "PRIMARY KEY ( SampleKey, TestNumber)); ";
		myExecSQL(QuerySQL);

		QuerySQL = "CREATE TABLE T_Journal ";
		QuerySQL = QuerySQL + "( ";
		QuerySQL = QuerySQL + "DHT_Entry varchar(15), ";
		QuerySQL = QuerySQL + "Type_Entry varchar(8), ";
		QuerySQL = QuerySQL + "Send_Receive varchar(1), ";
		QuerySQL = QuerySQL + "FileName varchar(50) ";
		QuerySQL = QuerySQL + "); ";
		myExecSQL(QuerySQL);
	}
	ReadConfig();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::bGenereClick(TObject *Sender)
{
	kryptorRequest myRequest;
	InitEmptyRequest(&myRequest);
	UnicodeToUtf8(myRequest.cPatientID, edtPatientID->Text.c_str(), LENGTH_SID);
	UnicodeToUtf8(myRequest.cPatientName, edtPatientName->Text.c_str(), 200);
	UnicodeToUtf8(myRequest.cPatientFirstName, edtPatientFirstname->Text.c_str(), 200);
	UnicodeToUtf8(myRequest.cPatientMaidenName, edtPatientMaidenName->Text.c_str(), 200);
	UnicodeToUtf8(myRequest.cSampleID, edtSampleID->Text.c_str(), LENGTH_SID);

	UnicodeToUtf8(myRequest.aKTR[0].cTest, cbTest1->Text.c_str(), LENGTH_TEST);
	myRequest.aKTR[0].iDilution=  StrToInt(edtDilution1->Text);
	UnicodeToUtf8(myRequest.aKTR[0].cType, cbType1->Text.c_str(), 2);
	UnicodeToUtf8(myRequest.aKTR[0].cSampleType, cbSampType1->Text.c_str(), 2);
	UnicodeToUtf8(myRequest.aKTR[0].cST, edtST1->Text.c_str(), 2);
	UnicodeToUtf8(myRequest.aKTR[0].cTubeType, edtTubeType1->Text.c_str(), 2);
	if (cbTest2->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[1].cTest, cbTest2->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[1].iDilution=  StrToInt(edtDilution2->Text);
		UnicodeToUtf8(myRequest.aKTR[1].cType, cbType2->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[1].cSampleType, cbSampType2->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[1].cST, edtST2->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[1].cTubeType, edtTubeType2->Text.c_str(), 2);
	}
	if (cbTest3->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[2].cTest, cbTest3->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[2].iDilution=  StrToInt(edtDilution3->Text);
		UnicodeToUtf8(myRequest.aKTR[2].cType, cbType3->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[2].cSampleType, cbSampType3->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[2].cST, edtST3->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[2].cTubeType, edtTubeType3->Text.c_str(), 2);
	}
	if (cbTest4->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[3].cTest, cbTest4->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[3].iDilution=  StrToInt(edtDilution4->Text);
		UnicodeToUtf8(myRequest.aKTR[3].cType, cbType4->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[3].cSampleType, cbSampType4->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[3].cST, edtST4->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[3].cTubeType, edtTubeType4->Text.c_str(), 2);
	}
	if (cbTest5->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[4].cTest, cbTest5->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[4].iDilution=  StrToInt(edtDilution5->Text);
		UnicodeToUtf8(myRequest.aKTR[4].cType, cbType5->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[4].cSampleType, cbSampType5->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[4].cST, edtST5->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[4].cTubeType, edtTubeType5->Text.c_str(), 2);
	}

	GenereTrame(myRequest);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::edtSampleIDExit(TObject *Sender)
{
	if (edtPatientID->Text == "")
		edtPatientID->Text = edtSampleID->Text;
}
//---------------------------------------------------------------------------

void TFMain::AddReceptMsg(UnicodeString sMsg)
{
	mRecept->Lines->Add(FormatDateTime("hh:mm:ss : ", Now()) + sMsg);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::shpReceptMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (shpRecept->Tag == 0)
	{
		shpRecept->Tag = 1;
		shpRecept->Brush->Color = clGreen;
		tRecept->Enabled = true;
		AddReceptMsg("ON");
	}
	else
	{
		shpRecept->Tag = 0;
		shpRecept->Brush->Color = clRed;
		tRecept->Enabled = false;
		AddReceptMsg("OFF");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::tReceptTimer(TObject *Sender)
{
	AddReceptMsg("Scanne");
	tRecept->Enabled = false;
	UnicodeString sChemin = IncludeTrailingPathDelimiter(Trim(edtReceivePath->Text));

	TSearchRec S;
	if (FindFirst(sChemin+"*.*",faAnyFile,S) == 0)
	{
		do
		{
			if ((S.Name != ".") && (S.Name != ".."))
			{
				if (S.Name.Pos(".") > 0)
					ReceivedFile(S.Name);
			}
		}
		while (FindNext(S) == 0);
		FindClose(S);
	}
	tRecept->Enabled = true;
}
//---------------------------------------------------------------------------

void TFMain::ReceivedFile(UnicodeString sFile)
{
	AddReceptMsg("Rec. : " + sFile);
	UnicodeString sInitPath = IncludeTrailingPathDelimiter(Trim(edtReceivePath->Text)) + sFile;
	UnicodeString sDestPath = IncludeTrailingPathDelimiter(IncludeTrailingPathDelimiter(Trim(edtReceivePath->Text)) + "Archive") + sFile;

	//Archivage de la trame
	UnicodeString sTypeFile = UpperCase(sFile.SubString(1, sFile.Pos(".")-1));
	UnicodeString sDH = FormatDateTime("YYYYMMDDHHMMSS", Now());
	UnicodeString sArchiveName = sDH + sTypeFile + ".TXT";
	if (FileExists(CheminArchive() + sArchiveName))
	{
		int iOk = 0;
		int i = 0;
		while (iOk == 0)
		{
			sArchiveName = sDH + sTypeFile + IntToStr(i++) + ".TXT";
			if (!FileExists(CheminArchive() + sArchiveName))
				iOk = 1;
		}
	}

	CopyFile(sInitPath.c_str(), (CheminArchive() + sArchiveName).c_str(), 0);
	AnsiString QuerySQL = "";
	QuerySQL = "INSERT INTO T_Journal (DHT_Entry, Type_Entry, Send_Receive, FileName) VALUES ";
	QuerySQL = QuerySQL + "( ";
	QuerySQL = QuerySQL + QuotedStr(sDH);
	QuerySQL = QuerySQL + ", ";
	QuerySQL = QuerySQL + QuotedStr(sTypeFile);
	QuerySQL = QuerySQL + ", ";
	QuerySQL = QuerySQL + QuotedStr("R");
	QuerySQL = QuerySQL + ", ";
	QuerySQL = QuerySQL + QuotedStr(sArchiveName);
	QuerySQL = QuerySQL + " ) ; ";
	myExecSQL(QuerySQL);
	//

	if (UpperCase(sFile.SubString(1, sFile.Pos(".")-1)) == "QUERY")
		TraiteQuery(sInitPath);
	else if (UpperCase(sFile.SubString(1, sFile.Pos(".")-1)) == "RESULT")
		TraiteResult(sInitPath);
	else
		AddReceptMsg("Type de fichier inconnu");
	MoveFile(sInitPath.c_str(), sDestPath.c_str());
	if (FileExists(sInitPath))
		DeleteFile(sInitPath.c_str());
}
//---------------------------------------------------------------------------

void TFMain::TraiteQuery(UnicodeString sQueryFile)
{
	AddReceptMsg("Q : " + sQueryFile);
	TStringList* tslQuery = new TStringList;
	tslQuery->LoadFromFile(sQueryFile);
	//ADU : vérifier l'en-tête et le fin de trame
	for (int i = 0; i < tslQuery->Count; i++)
	{
		if (tslQuery->Strings[i].SubString(1,1) == "Q")
		{
			//Vérification du numéro d'ordre ?
			UnicodeString sOrder = GetField(tslQuery->Strings[i], 1);
			UnicodeString sSampleID = GetField(tslQuery->Strings[i], 3);
			UnicodeString sTest = GetField(tslQuery->Strings[i], 5);;
			AddReceptMsg("N° : " + sOrder + " - SID : " + sSampleID + " - Test : " + sTest);
		}
	}
	delete tslQuery;
}
//---------------------------------------------------------------------------

void TFMain::TraiteResult(UnicodeString sResultFile)
{
	AddReceptMsg("R : " + sResultFile);
}
//---------------------------------------------------------------------------

UnicodeString TFMain::GetField(UnicodeString sLine, int iField)
{
	UnicodeString sRet;
	int iCrtField = 1;
	UnicodeString sTpo = sLine;
	while (sTpo != "")
	{
		if (sTpo.SubString(1, 1) == "|")
		{
			if (iCrtField == iField)
				sTpo = "";
			else
			{
				sTpo = sTpo.SubString(2, sTpo.Length());
				iCrtField++;
			}
		}
		else if (sTpo.Pos("|") > 0)
		{
			if (iCrtField == iField)
			{
				sRet = sTpo.SubString(1, sTpo.Pos("|")-1);
				sTpo = "";
			}
			else
			{
				sTpo = sTpo.SubString(sTpo.Pos("|")+1, sTpo.Length());
				iCrtField++;
            }

		}
		else if (iCrtField == iField)
		{
			sRet = sTpo;
			sTpo = "";
		}
	}
	return sRet;
}
//---------------------------------------------------------------------------

int TFMain::GenereTrame(kryptorRequest myRequest)
{
	UnicodeString sTrame;
	UnicodeString sSep = "|";
	UnicodeString sSep2 = "^";
	UnicodeString sSep3 = "~";

	mFile->Clear();
	//Trame Header
	sTrame = "";
	for (int i = 1; i <= 14; i++)
	{
		if (i == 1)
			sTrame = sTrame + "H" + sSep;
		else if (i == 2)
			sTrame = sTrame + edtCharacters->Text + sSep;
		else if (i == 5)
			sTrame = sTrame + edtSender->Text + sSep;
		else if (i == 10)
			sTrame = sTrame + edtReceiver->Text + sSep;
		else if (i == 12)
			sTrame = sTrame + "P" + sSep;
		else if (i == 13)
			sTrame = sTrame + edtVersion->Text + sSep;
		else if (i == 14)
			sTrame = sTrame + FormatDateTime("YYYMMDDHHMMSS", Now());
		else
			sTrame = sTrame + sSep;
	}
	mFile->Lines->Add(sTrame);

	//Trame Patient
	sTrame = "";
	int iSeqNumber = 1;
	for (int i = 1; i <= 19; i++)
	{
		if (i == 1)
			sTrame = sTrame + "P" + sSep;
		else if (i == 2)
			sTrame = sTrame + IntToStr(iSeqNumber++) + sSep;
		else if (i == 3) //Patient ID
			sTrame = sTrame + myRequest.cPatientID + sSep;
		else if (i == 6) //Patient Name
		{
			UnicodeString sPName = myRequest.cPatientName;
			UnicodeString sPFirstName = myRequest.cPatientFirstName;
			sTrame = sTrame + sPName + sSep2 + sPFirstName + sSep;
		}
		else if (i == 7) //Patient Maiden Name
			sTrame = sTrame + myRequest.cPatientMaidenName + sSep;
		//....
		else if (i == 19)
			sTrame = sTrame;
		else
			sTrame = sTrame + sSep;
	}
	mFile->Lines->Add(sTrame);

	//Trame Order
	sTrame = "";
	int iOrderSeqNumber = 1;
	for (int i = 1; i <= 20; i++)
	{
		if (i == 1)
			sTrame = sTrame + "OBR" + sSep;
		else if (i == 2)
			sTrame = sTrame + IntToStr(iOrderSeqNumber++) + sSep;
		else if (i == 3)  //Sample identification
			sTrame = sTrame + myRequest.cSampleID + sSep2 + "1" + sSep;
		else if (i == 5) //Test definition
		{
			for (int j = 0; j < MAX_TESTS; j++)
			{
				if (strcmp(myRequest.aKTR[j].cTest, "") != 0)
				{
					if (j > 0)
						sTrame = sTrame + sSep3;
					sTrame = sTrame + myRequest.aKTR[j].cTest;// + sSep2;
					if (myRequest.aKTR[j].iDilution != 1)
						sTrame = sTrame + sSep2 + IntToStr(myRequest.aKTR[j].iDilution);
					//				+ myRequest.aKTR[j].cPrev;
				}
			}
			sTrame = sTrame + sSep;
		}
		else if (i == 6) //R(outine) - A(sap) - S(tat)
			sTrame = sTrame + myRequest.aKTR[0].cType + sSep;
		else if (i == 12) //N(ew) A(dd the test) Q(control)
			sTrame = sTrame + myRequest.aKTR[0].cSampleType + sSep;
		else if (i == 16) //Sample Type + Tube type
			sTrame = sTrame + myRequest.aKTR[0].cST + sSep2
							+ myRequest.aKTR[0].cTubeType + sSep;
		//....
		else if (i == 20)
			sTrame = sTrame;
		else
			sTrame = sTrame + sSep;
	}
	mFile->Lines->Add(sTrame);

	//Trame Comment

	//Trame Terminator
	sTrame = "L|1|F";
	mFile->Lines->Add(sTrame);

	//Nom du fichier
	UnicodeString sFileName;
	int iOk = 0;
	int iIndice = 0;
	while (iOk != 1)
	{
		UnicodeString sIndice = IntToStr(iIndice);
		while (sIndice.Length() < 3)
				sIndice = "0" + sIndice;
		sFileName = edtSendPath->Text + "REQUEST." + sIndice;
		if (FileExists(sFileName))
		{
			//si Indice = 999 => Supprimer les fichiers et repartir à 0
			iIndice++;
		}
		else
			iOk = 1;
	}
	mFile->Lines->SaveToFile(sFileName);
	//Archivage de la trame
	UnicodeString sTypeFile = "REQUEST";
	UnicodeString sDH = FormatDateTime("YYYYMMDDHHMMSS", Now());
	UnicodeString sArchiveName = sDH + sTypeFile + ".TXT";
	if (FileExists(CheminArchive() + sArchiveName))
	{
		int iOk = 0;
		int i = 0;
		while (iOk == 0)
		{
			sArchiveName = sDH + sTypeFile + IntToStr(i++) + ".TXT";
			if (!FileExists(CheminArchive() + sArchiveName))
				iOk = 1;
		}
	}
	mFile->Lines->SaveToFile(CheminArchive() + sArchiveName);

	/*
	AnsiString QuerySQL = "";
	QuerySQL = "INSERT INTO T_Journal (DHT_Entry, Type_Entry, Send_Receive, FileName) VALUES ";
	QuerySQL = QuerySQL + "( ";
	QuerySQL = QuerySQL + QuotedStr(sDH);
	QuerySQL = QuerySQL + ", ";
	QuerySQL = QuerySQL + QuotedStr("REQUEST");
	QuerySQL = QuerySQL + ", ";
	QuerySQL = QuerySQL + QuotedStr("S");
	QuerySQL = QuerySQL + ", ";
	QuerySQL = QuerySQL + QuotedStr(sArchiveName);
	QuerySQL = QuerySQL + " ) ; ";
	myExecSQL(QuerySQL);
	*/
	//

	return 1;
}
//---------------------------------------------------------------------------

void TFMain::InitEmptyRequest(kryptorRequest *myRequest)
{
	strcpy(myRequest->cSampleID, "");
	strcpy(myRequest->cPatientID, "");
	strcpy(myRequest->cPatientName, "");
	strcpy(myRequest->cPatientFirstName, "");
	strcpy(myRequest->cPatientMaidenName, "");
	for (int i = 0; i < MAX_TESTS; i++)
	{
		strcpy(myRequest->aKTR[i].cTest, "");
		myRequest->aKTR[i].iDilution = 0;
		strcpy(myRequest->aKTR[i].cPrev, "");
		strcpy(myRequest->aKTR[i].cType, "");
		strcpy(myRequest->aKTR[i].cSampleType, "");
		strcpy(myRequest->aKTR[i].cST, "");
		strcpy(myRequest->aKTR[i].cTubeType, "");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::bSauveBDClick(TObject *Sender)
{
	kryptorRequest myRequest;
	InitEmptyRequest(&myRequest);
	UnicodeToUtf8(myRequest.cPatientID, edtPatientID->Text.c_str(), LENGTH_SID);
	UnicodeToUtf8(myRequest.cPatientName, edtPatientName->Text.c_str(), 200);
	UnicodeToUtf8(myRequest.cPatientFirstName, edtPatientFirstname->Text.c_str(), 200);
	UnicodeToUtf8(myRequest.cPatientMaidenName, edtPatientMaidenName->Text.c_str(), 200);
	UnicodeToUtf8(myRequest.cSampleID, edtSampleID->Text.c_str(), LENGTH_SID);

	UnicodeToUtf8(myRequest.aKTR[0].cTest, cbTest1->Text.c_str(), LENGTH_TEST);
	myRequest.aKTR[0].iDilution=  StrToInt(edtDilution1->Text);
	UnicodeToUtf8(myRequest.aKTR[0].cType, cbType1->Text.c_str(), 2);
	UnicodeToUtf8(myRequest.aKTR[0].cSampleType, cbSampType1->Text.c_str(), 2);
	UnicodeToUtf8(myRequest.aKTR[0].cST, edtST1->Text.c_str(), 2);
	UnicodeToUtf8(myRequest.aKTR[0].cTubeType, edtTubeType1->Text.c_str(), 2);
	if (cbTest2->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[1].cTest, cbTest2->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[1].iDilution=  StrToInt(edtDilution2->Text);
		UnicodeToUtf8(myRequest.aKTR[1].cType, cbType2->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[1].cSampleType, cbSampType2->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[1].cST, edtST2->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[1].cTubeType, edtTubeType2->Text.c_str(), 2);
	}
	if (cbTest3->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[2].cTest, cbTest3->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[2].iDilution=  StrToInt(edtDilution3->Text);
		UnicodeToUtf8(myRequest.aKTR[2].cType, cbType3->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[2].cSampleType, cbSampType3->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[2].cST, edtST3->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[2].cTubeType, edtTubeType3->Text.c_str(), 2);
	}
	if (cbTest4->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[3].cTest, cbTest4->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[3].iDilution=  StrToInt(edtDilution4->Text);
		UnicodeToUtf8(myRequest.aKTR[3].cType, cbType4->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[3].cSampleType, cbSampType4->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[3].cST, edtST4->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[3].cTubeType, edtTubeType4->Text.c_str(), 2);
	}
	if (cbTest5->ItemIndex >= 0)
	{
		UnicodeToUtf8(myRequest.aKTR[4].cTest, cbTest5->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[4].iDilution=  StrToInt(edtDilution5->Text);
		UnicodeToUtf8(myRequest.aKTR[4].cType, cbType5->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[4].cSampleType, cbSampType5->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[4].cST, edtST5->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[4].cTubeType, edtTubeType5->Text.c_str(), 2);
	}

	SauveTrameBD(myRequest);

}
//---------------------------------------------------------------------------

int TFMain::SauveTrameBD(kryptorRequest myRequest)
{
	int iRet = 0;
	Screen->Cursor = crHourGlass;
	AnsiString QuerySQL = "";
	sqlite3 *db = NULL;
	int rc;
	char *zErrMsg = 0;
	char cBDPath[500];
	UnicodeToUtf8(cBDPath, CheminBD().c_str(), 500);
	rc = sqlite3_open(cBDPath, &db);

	int iKey = -1;
	if(rc != SQLITE_OK)
	{
		UnicodeString sMsgError = sqlite3_errmsg(db);
		MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
		sqlite3_close(db);
	}
	else
	{
		QuerySQL = "SELECT MAX(SampleKey) as MaxKey FROM T_Samples ;";
		sqlite3_stmt *stmt;
		rc = sqlite3_prepare_v2(db, QuerySQL.c_str(), -1, &stmt, 0);
		if(rc != SQLITE_OK)
		{
			UnicodeString sMsgError = zErrMsg;
			MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
			sqlite3_free(zErrMsg);
		}
		else if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			if (sqlite3_column_text(stmt, 0) == NULL)
				iKey = 1;
			else
				iKey = sqlite3_column_int(stmt, 0)+1;
		}
		else
			iKey = 1;
		sqlite3_finalize(stmt);
	}
	sqlite3_close(db);
	db = NULL;

	if (iKey >= 0)
	{
		//ShowMessage(IntToStr(iKey));
		QuerySQL = "INSERT INTO T_Samples (SampleKey, SampleID, PatientID, PName, PFirstN, PMaidenN) VALUES ";
		QuerySQL = QuerySQL + "( " + IntToStr(iKey) + ", ";
		QuerySQL = QuerySQL + QuotedStr(myRequest.cSampleID);
		QuerySQL = QuerySQL + ", ";
		QuerySQL = QuerySQL + QuotedStr(myRequest.cPatientID);
		QuerySQL = QuerySQL + ", ";
		QuerySQL = QuerySQL + QuotedStr(myRequest.cPatientName);
		QuerySQL = QuerySQL + ", ";
		QuerySQL = QuerySQL + QuotedStr(myRequest.cPatientFirstName);
		QuerySQL = QuerySQL + ", ";
		QuerySQL = QuerySQL + QuotedStr(myRequest.cPatientMaidenName);
		QuerySQL = QuerySQL + " ) ; ";
		rc = myExecSQL(QuerySQL);
		if(rc == SQLITE_OK)
		{
			//Sauvegarde des tests
			int iNumOrdre = 1;
			while ((iNumOrdre <= MAX_TESTS) && (strcmp(myRequest.aKTR[iNumOrdre-1].cTest, "") != 0))
			{
				QuerySQL = "INSERT INTO T_Tests (SampleKey, TestNumber, TestName, Dilution, TestType, SampleType, ST, TubeType) VALUES ";
				QuerySQL = QuerySQL + "( " + IntToStr(iKey) + ", ";
				QuerySQL = QuerySQL + IntToStr(iNumOrdre) + ", ";
				QuerySQL = QuerySQL + QuotedStr(myRequest.aKTR[iNumOrdre-1].cTest);
				QuerySQL = QuerySQL + ", ";
				QuerySQL = QuerySQL + IntToStr(myRequest.aKTR[iNumOrdre-1].iDilution);
				QuerySQL = QuerySQL + ", ";
				QuerySQL = QuerySQL + QuotedStr(myRequest.aKTR[iNumOrdre-1].cType);
				QuerySQL = QuerySQL + ", ";
				QuerySQL = QuerySQL + QuotedStr(myRequest.aKTR[iNumOrdre-1].cSampleType);
				QuerySQL = QuerySQL + ", ";
				QuerySQL = QuerySQL + QuotedStr(myRequest.aKTR[iNumOrdre-1].cST);
				QuerySQL = QuerySQL + ", ";
				QuerySQL = QuerySQL + QuotedStr(myRequest.aKTR[iNumOrdre-1].cTubeType);
				QuerySQL = QuerySQL + " ) ; ";
				iNumOrdre++;
				myExecSQL(QuerySQL);
			}
		}
	}
	Screen->Cursor = crDefault;
	//ShowMessage("Fin de traitement");
	return iRet;
}
//---------------------------------------------------------------------------

UnicodeString TFMain::CheminBD()
{
	return IncludeTrailingPathDelimiter(ExtractFilePath(Application->ExeName)) + "BD_LIS.db3";
}
//---------------------------------------------------------------------------

UnicodeString TFMain::CheminArchive()
{
	return IncludeTrailingPathDelimiter(ExtractFilePath(Application->ExeName)) + "Archive\\";
}
//---------------------------------------------------------------------------

void __fastcall TFMain::bInitClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;

	//
	for (int i = sgBD->FixedRows; i < sgBD->RowCount; i++)
	{
		for (int j = sgBD->FixedCols; j < sgBD->ColCount; j++)
			sgBD->Cells[j][i] = "";
	}
	sgBD->RowCount = 2;
	//

	AnsiString QuerySQL = "";
	sqlite3 *db = NULL;
	int rc;
	char *zErrMsg = 0;
	char cBDPath[500];
	UnicodeToUtf8(cBDPath, CheminBD().c_str(), 500);
	rc = sqlite3_open(cBDPath, &db);

	if(rc != SQLITE_OK)
	{
		UnicodeString sMsgError = sqlite3_errmsg(db);
		MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
		sqlite3_close(db);
	}
	else
	{
		int iKey = -1;
		QuerySQL = "SELECT * FROM T_Samples ORDER BY SampleKey;";
		sqlite3_stmt *stmt;
		rc = sqlite3_prepare_v2(db, QuerySQL.c_str(), -1, &stmt, 0);
		if(rc != SQLITE_OK)
		{
			UnicodeString sMsgError = zErrMsg;
			MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
			sqlite3_free(zErrMsg);
		}
		else
		{
			int iLine = sgBD->FixedRows;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sgBD->RowCount <= iLine)
					sgBD->RowCount = iLine + 1;
				sgBD->Cells[0][iLine] = IntToStr(sqlite3_column_int(stmt, 0));
				char cValue[200];
				strcpy(cValue,sqlite3_column_text(stmt, 1));
				sgBD->Cells[1][iLine] = cValue;
				strcpy(cValue,sqlite3_column_text(stmt, 2));
				sgBD->Cells[2][iLine] = cValue;
				strcpy(cValue,sqlite3_column_text(stmt, 3));
				sgBD->Cells[3][iLine] = cValue;

				//Tests
				int iKey = sqlite3_column_int(stmt, 0);
				sqlite3_stmt *stmtTests;
				AnsiString QuerySQLTest = "SELECT * FROM T_Tests WHERE (SampleKey = " + IntToStr(iKey) + ") ORDER BY TestNumber;";
				rc = sqlite3_prepare_v2(db, QuerySQLTest.c_str(), -1, &stmtTests, 0);
				if(rc != SQLITE_OK)
				{
					UnicodeString sMsgError = zErrMsg;
					MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
					sqlite3_free(zErrMsg);
				}
				else
				{
					UnicodeString sTests = "";
					while (sqlite3_step(stmtTests) == SQLITE_ROW)
					{
						if (sTests != "")
							sTests = sTests + " | ";
						sTests = sTests + IntToStr(sqlite3_column_int(stmtTests, 1));
						sTests = sTests + L" : ";
						char cValue[200];
						strcpy(cValue,sqlite3_column_text(stmtTests, 2));
						sTests = sTests + cValue;
						sTests = sTests + "/";
						sTests = sTests + IntToStr(sqlite3_column_int(stmtTests, 3));
					}
					sgBD->Cells[4][iLine] = sTests;
				}
				sqlite3_finalize(stmtTests);
				//!Tests

				iLine++;
			}
		}
		sqlite3_finalize(stmt);

	}

	//Fermeture de la connexion
	sqlite3_close(db);
	Screen->Cursor = crDefault;
	//ShowMessage("Fin de traitement");
}
//---------------------------------------------------------------------------

void __fastcall TFMain::bSendClick(TObject *Sender)
{
	if ((sgBD->Row < sgBD->RowCount) && (sgBD->Row >= sgBD->FixedRows)
		&& (sgBD->Cells[0][sgBD->Row] != ""))
	{
		GenereTrameBD(StrToInt(sgBD->Cells[0][sgBD->Row]));
	}
}
//---------------------------------------------------------------------------

int TFMain::GenereTrameBD(int iKey)
{
	Screen->Cursor = crHourGlass;
	AnsiString QuerySQL = "";
	sqlite3 *db = NULL;
	int rc;
	char *zErrMsg = 0;
	char cBDPath[500];
	UnicodeToUtf8(cBDPath, CheminBD().c_str(), 500);
	rc = sqlite3_open(cBDPath, &db);
	kryptorRequest myRequest;
	InitEmptyRequest(&myRequest);
	int iOk = 0;

	if(rc != SQLITE_OK)
	{
		UnicodeString sMsgError = sqlite3_errmsg(db);
		MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
		sqlite3_close(db);
	}
	else
	{
		QuerySQL = "SELECT * FROM T_Samples WHERE (SampleKey = "  + IntToStr(iKey) + " ) ;";
		sqlite3_stmt *stmt;
		rc = sqlite3_prepare_v2(db, QuerySQL.c_str(), -1, &stmt, 0);
		if(rc != SQLITE_OK)
		{
			UnicodeString sMsgError = zErrMsg;
			MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
			sqlite3_free(zErrMsg);
		}
		else
		{
			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				strcpy(myRequest.cPatientID, sqlite3_column_text(stmt, 2));
				strcpy(myRequest.cPatientName, sqlite3_column_text(stmt, 3));
				strcpy(myRequest.cPatientFirstName, sqlite3_column_text(stmt, 4));
				strcpy(myRequest.cPatientMaidenName, sqlite3_column_text(stmt, 5));
				strcpy(myRequest.cSampleID, sqlite3_column_text(stmt, 1));

				int iInd = 0;

				//Tests
				sqlite3_stmt *stmtTests;
				AnsiString QuerySQLTest = "SELECT * FROM T_Tests WHERE (SampleKey = " + IntToStr(iKey) + ") ORDER BY TestNumber;";
				rc = sqlite3_prepare_v2(db, QuerySQLTest.c_str(), -1, &stmtTests, 0);
				if(rc != SQLITE_OK)
				{
					UnicodeString sMsgError = zErrMsg;
					MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
					sqlite3_free(zErrMsg);
				}
				else
				{
					while (sqlite3_step(stmtTests) == SQLITE_ROW)
					{
						strcpy(myRequest.aKTR[iInd].cTest, sqlite3_column_text(stmtTests, 2));
						myRequest.aKTR[iInd].iDilution = sqlite3_column_int(stmtTests, 3);
						strcpy(myRequest.aKTR[iInd].cType, sqlite3_column_text(stmtTests, 4));
						strcpy(myRequest.aKTR[iInd].cSampleType, sqlite3_column_text(stmtTests, 5));
						strcpy(myRequest.aKTR[iInd].cST, sqlite3_column_text(stmtTests, 6));
						strcpy(myRequest.aKTR[iInd].cST, sqlite3_column_text(stmtTests, 7));
						iInd++;
						iOk = 1;
					}
				}
				sqlite3_finalize(stmtTests);
				//!Tests
			}
		}
		sqlite3_finalize(stmt);

	}

	//Fermeture de la connexion
	sqlite3_close(db);
	if (iOk)
		GenereTrame(myRequest);
	Screen->Cursor = crDefault;
	//ShowMessage("Fin de traitement");
}

void __fastcall TFMain::bDeleteClick(TObject *Sender)
{
	if ((sgBD->Row < sgBD->RowCount) && (sgBD->Row >= sgBD->FixedRows)
		&& (sgBD->Cells[0][sgBD->Row] != ""))
	{
		UnicodeString sMsgConf = L"Confirmez-vous la suppression du dossier n° " + sgBD->Cells[0][sgBD->Row];

		if (MessageDlg(sMsgConf, mtConfirmation, mbYesNo, 0) == mrYes)
		{
			AnsiString QuerySQL = "";
			QuerySQL = "DELETE FROM T_Tests WHERE (SampleKey = "  + sgBD->Cells[0][sgBD->Row] + " ) ;";
			int rc = myExecSQL(QuerySQL);
			if(rc == SQLITE_OK)
			{
				QuerySQL = "DELETE FROM T_Samples WHERE (SampleKey = "  + sgBD->Cells[0][sgBD->Row] + " ) ;";
				myExecSQL(QuerySQL);
			}
            bInit->Click();
        }
	}
}
//---------------------------------------------------------------------------

void TFMain::ReadConfig()
{
	edtSendPath->Text = LitIni("Config", "SendPath", "C:\\KLIS\\DOWNLOAD\\");
	edtReceivePath->Text = LitIni("Config", "ReceivePath", "C:\\KLIS\\UPLOAD\\");
	edtCharacters->Text = LitIni("Config", "Characters", "^~\\&");
	edtSender->Text = LitIni("Config", "Sender", "ORM");
	edtReceiver->Text = LitIni("Config", "Receiver", "KRYPTOR");
	edtVersion->Text = LitIni("Config", "Version", "H1.2");
}
//---------------------------------------------------------------------------

void TFMain::WriteConfig()
{
	EcritIni("Config", "SendPath", edtSendPath->Text);
	EcritIni("Config", "ReceivePath", edtReceivePath->Text);
	EcritIni("Config", "Characters", edtCharacters->Text);
	EcritIni("Config", "Sender", edtSender->Text);
	EcritIni("Config", "Receiver", edtReceiver->Text);
	EcritIni("Config", "Version", edtVersion->Text);
}
//---------------------------------------------------------------------------


void __fastcall TFMain::bSaveConfigClick(TObject *Sender)
{
	WriteConfig();
}
//---------------------------------------------------------------------------

UnicodeString TFMain::LitIni(UnicodeString section, UnicodeString rubrique, UnicodeString valeur)
{
	UnicodeString NomFichier = IncludeTrailingPathDelimiter(ExtractFilePath(Application->ExeName)) + "SimuLIS.ini";
	UnicodeString sRetour = "";
	TIniFile * iniFile = new TIniFile(NomFichier);
	try
	{
		sRetour = iniFile->ReadString(section,rubrique,valeur);
	}
	__finally
	{
		iniFile->Free();
	}
	return sRetour;
}
//---------------------------------------------------------------------------

void TFMain::EcritIni(UnicodeString section, UnicodeString rubrique, UnicodeString valeur)
{
	UnicodeString NomFichier = IncludeTrailingPathDelimiter(ExtractFilePath(Application->ExeName)) + "SimuLIS.ini";
	UnicodeString sRetour = "";
	TIniFile * iniFile = new TIniFile(NomFichier);
	try
	{
		iniFile->WriteString(section,rubrique,valeur);
	}
	__finally
	{
		iniFile->Free();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::bInitJournalClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;

	//
	for (int i = sgJournal->FixedRows; i < sgJournal->RowCount; i++)
	{
		for (int j = sgJournal->FixedCols; j < sgJournal->ColCount; j++)
			sgJournal->Cells[j][i] = "";
	}
	sgJournal->RowCount = 2;
	//

	AnsiString QuerySQL = "";
	sqlite3 *db = NULL;
	int rc;
	char *zErrMsg = 0;
	char cBDPath[500];
	UnicodeToUtf8(cBDPath, CheminBD().c_str(), 500);
	rc = sqlite3_open(cBDPath, &db);

	if(rc != SQLITE_OK)
	{
		//MessageBox(NULL, sqlite3_errmsg(db), "SQL error", MB_ICONERROR);
		sqlite3_close(db);
	}
	else
	{
		int iKey = -1;
		QuerySQL = "SELECT * FROM T_Journal ORDER BY DHT_Entry;";
		sqlite3_stmt *stmt;
		rc = sqlite3_prepare_v2(db, QuerySQL.c_str(), -1, &stmt, 0);
		if(rc != SQLITE_OK)
		{
			//mScript->Lines->Add("Table : " + lbTables->Items->Strings[lbTables->ItemIndex] + "Problem Database Error Code: " + IntToStr(rc).c_str());
			sqlite3_free(zErrMsg);
		}
		else
		{
			int iLine = sgJournal->FixedRows;
			while (sqlite3_step(stmt) == SQLITE_ROW)
			{
				if (sgJournal->RowCount <= iLine)
					sgJournal->RowCount = iLine + 1;
				char cValue[200];
				strcpy(cValue,sqlite3_column_text(stmt, 0));
				sgJournal->Cells[0][iLine] = cValue;
				strcpy(cValue,sqlite3_column_text(stmt, 1));
				sgJournal->Cells[1][iLine] = cValue;
				strcpy(cValue,sqlite3_column_text(stmt, 2));
				sgJournal->Cells[2][iLine] = cValue;
				strcpy(cValue,sqlite3_column_text(stmt, 3));
				sgJournal->Cells[3][iLine] = cValue;

				iLine++;
			}
		}
		sqlite3_finalize(stmt);
	}

	//Fermeture de la connexion
	sqlite3_close(db);
	Screen->Cursor = crDefault;
	//ShowMessage("Fin de traitement");

}
//---------------------------------------------------------------------------

void __fastcall TFMain::sgJournalDblClick(TObject *Sender)
{
	UnicodeString sFilePath = CheminArchive() + sgJournal->Cells[3][sgJournal->Row];
	if (FileExists(sFilePath.c_str()))
	{
		mArchive->Clear();
		mArchive->Lines->LoadFromFile(sFilePath.c_str());
	}
	else
		ShowMessage(sFilePath);
}
//---------------------------------------------------------------------------

int TFMain::myExecSQL(AnsiString sSQL)
{
	sqlite3 *db = NULL;
	int rc;
	char *zErrMsg = 0;
	char cBDPath[500];
	UnicodeToUtf8(cBDPath, CheminBD().c_str(), 500);
	rc = sqlite3_open(cBDPath, &db);
	if(rc != SQLITE_OK)
	{
		UnicodeString sMsgError = sqlite3_errmsg(db);
		MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
		sqlite3_close(db);
	}
	else
	{
		rc = sqlite3_exec(db, sSQL.c_str(), 0, 0, &zErrMsg);
		if(rc != SQLITE_OK)
		{
			UnicodeString sMsgError = zErrMsg;
			MessageBox(NULL, sMsgError.c_str(), L"SQL error", MB_ICONERROR);
			sMsgError = sSQL;
			MessageBox(NULL,  sMsgError.c_str(), L"SQL error", MB_ICONERROR);
			sqlite3_free(zErrMsg);
		}
	}
	sqlite3_close(db);
	return rc;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::bGenXClick(TObject *Sender)
{
	for (int i = 0; i < seNb->Value; i++) {
		kryptorRequest myRequest;
		InitEmptyRequest(&myRequest);
		UnicodeString SPID = edtPatientID->Text + IntToStr(seInit->Value + i);
		UnicodeToUtf8(myRequest.cPatientID, SPID.c_str(), LENGTH_SID);
		UnicodeString SPName = edtPatientName->Text + IntToStr(seInit->Value + i);
		UnicodeToUtf8(myRequest.cPatientName, SPName.c_str(), 200);
		UnicodeToUtf8(myRequest.cPatientFirstName, edtPatientFirstname->Text.c_str(), 200);
		UnicodeToUtf8(myRequest.cPatientMaidenName, edtPatientMaidenName->Text.c_str(), 200);
		UnicodeString SSID = edtSampleID->Text + IntToStr(seInit->Value + i);
		UnicodeToUtf8(myRequest.cSampleID, SSID.c_str(), LENGTH_SID);

		UnicodeToUtf8(myRequest.aKTR[0].cTest, cbTest1->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[0].iDilution=  StrToInt(edtDilution1->Text);
		UnicodeToUtf8(myRequest.aKTR[0].cType, cbType1->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[0].cSampleType, cbSampType1->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[0].cST, edtST1->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[0].cTubeType, edtTubeType1->Text.c_str(), 2);
		if (cbTest2->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[1].cTest, cbTest2->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[1].iDilution=  StrToInt(edtDilution2->Text);
			UnicodeToUtf8(myRequest.aKTR[1].cType, cbType2->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[1].cSampleType, cbSampType2->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[1].cST, edtST2->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[1].cTubeType, edtTubeType2->Text.c_str(), 2);
		}
		if (cbTest3->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[2].cTest, cbTest3->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[2].iDilution=  StrToInt(edtDilution3->Text);
			UnicodeToUtf8(myRequest.aKTR[2].cType, cbType3->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[2].cSampleType, cbSampType3->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[2].cST, edtST3->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[2].cTubeType, edtTubeType3->Text.c_str(), 2);
		}
		if (cbTest4->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[3].cTest, cbTest4->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[3].iDilution=  StrToInt(edtDilution4->Text);
			UnicodeToUtf8(myRequest.aKTR[3].cType, cbType4->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[3].cSampleType, cbSampType4->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[3].cST, edtST4->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[3].cTubeType, edtTubeType4->Text.c_str(), 2);
		}
		if (cbTest5->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[4].cTest, cbTest5->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[4].iDilution=  StrToInt(edtDilution5->Text);
			UnicodeToUtf8(myRequest.aKTR[4].cType, cbType5->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[4].cSampleType, cbSampType5->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[4].cST, edtST5->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[4].cTubeType, edtTubeType5->Text.c_str(), 2);
		}

		GenereTrame(myRequest);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::TTrackTimer(TObject *Sender)
{
	Screen->Cursor = crHourGlass;
	for (int i = 0; i < seTestsCycle->Value; i++) {
		kryptorRequest myRequest;
		InitEmptyRequest(&myRequest);
		UnicodeString SSID = edtSampleID->Text;
		UnicodeToUtf8(myRequest.cSampleID, SSID.c_str(), LENGTH_SID);
		sbNbTestIDRestant->Value--;
		if (sbNbTestIDRestant->Value <= 0) {
			edtSampleID->Text = IntToStr(StrToInt(edtSampleID->Text) + 1);
			sbNbTestIDRestant->Value = sbNbTestID->Value;
		}
		UnicodeToUtf8(myRequest.aKTR[0].cTest, cbTest1->Text.c_str(), LENGTH_TEST);
		myRequest.aKTR[0].iDilution=  StrToInt(edtDilution1->Text);
		UnicodeToUtf8(myRequest.aKTR[0].cType, cbType1->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[0].cSampleType, cbSampType1->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[0].cST, edtST1->Text.c_str(), 2);
		UnicodeToUtf8(myRequest.aKTR[0].cTubeType, edtTubeType1->Text.c_str(), 2);
		if (cbTest2->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[1].cTest, cbTest2->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[1].iDilution=  StrToInt(edtDilution2->Text);
			UnicodeToUtf8(myRequest.aKTR[1].cType, cbType2->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[1].cSampleType, cbSampType2->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[1].cST, edtST2->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[1].cTubeType, edtTubeType2->Text.c_str(), 2);
		}
		if (cbTest3->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[2].cTest, cbTest3->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[2].iDilution=  StrToInt(edtDilution3->Text);
			UnicodeToUtf8(myRequest.aKTR[2].cType, cbType3->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[2].cSampleType, cbSampType3->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[2].cST, edtST3->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[2].cTubeType, edtTubeType3->Text.c_str(), 2);
		}
		if (cbTest4->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[3].cTest, cbTest4->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[3].iDilution=  StrToInt(edtDilution4->Text);
			UnicodeToUtf8(myRequest.aKTR[3].cType, cbType4->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[3].cSampleType, cbSampType4->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[3].cST, edtST4->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[3].cTubeType, edtTubeType4->Text.c_str(), 2);
		}
		if (cbTest5->ItemIndex >= 0)
		{
			UnicodeToUtf8(myRequest.aKTR[4].cTest, cbTest5->Text.c_str(), LENGTH_TEST);
			myRequest.aKTR[4].iDilution=  StrToInt(edtDilution5->Text);
			UnicodeToUtf8(myRequest.aKTR[4].cType, cbType5->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[4].cSampleType, cbSampType5->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[4].cST, edtST5->Text.c_str(), 2);
			UnicodeToUtf8(myRequest.aKTR[4].cTubeType, edtTubeType5->Text.c_str(), 2);
		}

		GenereTrame(myRequest);
		seMaxTests->Value--;
		if (seMaxTests->Value <= 0) {
			i = seTestsCycle->Value+1;
			bTestTrack->Click();
		}
	}
	Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::bTestTrackClick(TObject *Sender)
{
	Screen->Cursor = crHourGlass;
	if (TTrack->Enabled) {
		bTestTrack->Caption = "Go";
		TTrack->Enabled = false;
	}
	else {
		if (edtSampleID->Text == "")
			edtSampleID->Text = "1000";

		bTestTrack->Caption = "Stop";
		TTrack->Interval = seDelai->Value * 1000 * 60;
		TTrackTimer(TTrack);
		TTrack->Enabled = true;
	}
	Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

