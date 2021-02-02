//---------------------------------------------------------------------------

#ifndef UFMainH
#define UFMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "sqlite3.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <IniFiles.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
#define LENGTH_SID 15
#define LENGTH_TEST 15
#define MAX_TESTS 10
typedef struct {

	char cTest[LENGTH_TEST] ;
	int iDilution;
	char cPrev [200] ;
	char cType [5] ;
	char cSampleType [5] ;
	char cST [5] ;
	char cTubeType [5] ;
} kryptorTestRequest ;

typedef struct {

	char cSampleID[LENGTH_SID] ;
	char cPatientID [LENGTH_SID] ;
	char cPatientName [200] ;
	char cPatientFirstName [200] ;
	char cPatientMaidenName [200] ;
	kryptorTestRequest aKTR[MAX_TESTS] ;

} kryptorRequest ;

//---------------------------------------------------------------------------
class TFMain : public TForm
{
__published:	// Composants gérés par l'EDI
	TPanel *pConfig;
	TEdit *edtSendPath;
	TLabel *Label1;
	TLabel *Label5;
	TEdit *edtSender;
	TLabel *Label6;
	TEdit *edtReceiver;
	TLabel *Label7;
	TEdit *edtVersion;
	TLabel *Label8;
	TEdit *edtCharacters;
	TMemo *mFile;
	TLabel *Label22;
	TEdit *edtReceivePath;
	TShape *shpRecept;
	TTimer *tRecept;
	TMemo *mRecept;
	TPageControl *pcLIS;
	TTabSheet *tsSendRecept;
	TTabSheet *tsBD;
	TPanel *pSendData;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label9;
	TLabel *Label2;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label24;
	TEdit *edtPatientID;
	TEdit *edtPatientName;
	TEdit *edtPatientFirstname;
	TEdit *edtPatientMaidenName;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *edtSampleID;
	TEdit *edtDilution1;
	TEdit *edtPrev1;
	TEdit *edtST1;
	TEdit *edtTubeType1;
	TButton *bGenere;
	TComboBox *cbTest1;
	TComboBox *cbType1;
	TComboBox *cbSampType1;
	TComboBox *cbTest2;
	TEdit *edtDilution2;
	TEdit *edtPrev2;
	TComboBox *cbType2;
	TComboBox *cbSampType2;
	TEdit *edtST2;
	TEdit *edtTubeType2;
	TComboBox *cbTest3;
	TEdit *edtDilution3;
	TEdit *edtPrev3;
	TComboBox *cbType3;
	TComboBox *cbSampType3;
	TEdit *edtST3;
	TEdit *edtTubeType3;
	TComboBox *cbTest4;
	TEdit *edtDilution4;
	TEdit *edtPrev4;
	TComboBox *cbType4;
	TComboBox *cbSampType4;
	TEdit *edtST4;
	TEdit *edtTubeType4;
	TComboBox *cbTest5;
	TEdit *edtDilution5;
	TEdit *edtPrev5;
	TComboBox *cbType5;
	TComboBox *cbSampType5;
	TEdit *edtST5;
	TEdit *edtTubeType5;
	TButton *bSauveBD;
	TStringGrid *sgBD;
	TButton *bInit;
	TButton *bSend;
	TButton *bDelete;
	TButton *bSaveConfig;
	TTabSheet *tsJournal;
	TStringGrid *sgJournal;
	TButton *bInitJournal;
	TMemo *mArchive;
	TSpinEdit *seInit;
	TSpinEdit *seNb;
	TButton *bGenX;
	TPanel *pnlTrack;
	TSpinEdit *seTestsCycle;
	TSpinEdit *seDelai;
	TButton *bTestTrack;
	TLabel *Label23;
	TLabel *Label25;
	TTimer *TTrack;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TSpinEdit *sbNbTestID;
	TLabel *Label29;
	TSpinEdit *sbNbTestIDRestant;
	TLabel *Label30;
	TSpinEdit *seMaxTests;
	void __fastcall bGenereClick(TObject *Sender);
	void __fastcall edtSampleIDExit(TObject *Sender);
	void __fastcall tReceptTimer(TObject *Sender);
	void __fastcall shpReceptMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall bSauveBDClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall bInitClick(TObject *Sender);
	void __fastcall bSendClick(TObject *Sender);
	void __fastcall bDeleteClick(TObject *Sender);
	void __fastcall bSaveConfigClick(TObject *Sender);
	void __fastcall bInitJournalClick(TObject *Sender);
	void __fastcall sgJournalDblClick(TObject *Sender);
	void __fastcall bGenXClick(TObject *Sender);
	void __fastcall TTrackTimer(TObject *Sender);
	void __fastcall bTestTrackClick(TObject *Sender);

private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
	__fastcall TFMain(TComponent* Owner);
	void AddReceptMsg(UnicodeString sMsg);
	void ReceivedFile(UnicodeString sFile);
	void TraiteQuery(UnicodeString sQueryFile);
	void TraiteResult(UnicodeString sResultFile);
	UnicodeString GetField(UnicodeString sLine, int iField);
	int GenereTrame(kryptorRequest myRequest);
	void InitEmptyRequest(kryptorRequest *myRequest);
	int SauveTrameBD(kryptorRequest myRequest);
	int GenereTrameBD(int iKey);
	UnicodeString CheminBD();
	UnicodeString CheminArchive();
	void ReadConfig();
	void WriteConfig();
	UnicodeString LitIni(UnicodeString section, UnicodeString rubrique, UnicodeString valeur);
	void EcritIni(UnicodeString section, UnicodeString rubrique, UnicodeString valeur);
	int myExecSQL(AnsiString sSQL);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
