object FMain: TFMain
  Left = 0
  Top = 0
  Caption = 'LIS Simul'
  ClientHeight = 727
  ClientWidth = 655
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object pConfig: TPanel
    Left = 4
    Top = 8
    Width = 652
    Height = 97
    BevelOuter = bvNone
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 11
      Width = 66
      Height = 13
      Caption = 'R'#233'p. '#233'mission'
    end
    object Label5: TLabel
      Left = 368
      Top = 11
      Width = 44
      Height = 13
      Caption = 'Emetteur'
    end
    object Label6: TLabel
      Left = 368
      Top = 38
      Width = 50
      Height = 13
      Caption = 'R'#233'cepteur'
    end
    object Label7: TLabel
      Left = 368
      Top = 65
      Width = 35
      Height = 13
      Caption = 'Version'
    end
    object Label8: TLabel
      Left = 16
      Top = 65
      Width = 53
      Height = 13
      Caption = 'Characters'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label22: TLabel
      Left = 16
      Top = 38
      Width = 71
      Height = 13
      Caption = 'R'#233'p. r'#233'ception'
    end
    object shpRecept: TShape
      Left = 560
      Top = 8
      Width = 30
      Height = 30
      Brush.Color = clRed
      OnMouseUp = shpReceptMouseUp
    end
    object edtSendPath: TEdit
      Left = 96
      Top = 8
      Width = 249
      Height = 21
      TabOrder = 0
    end
    object edtSender: TEdit
      Left = 448
      Top = 8
      Width = 97
      Height = 21
      TabOrder = 1
    end
    object edtReceiver: TEdit
      Left = 448
      Top = 35
      Width = 97
      Height = 21
      TabOrder = 2
    end
    object edtVersion: TEdit
      Left = 448
      Top = 62
      Width = 97
      Height = 21
      TabOrder = 3
    end
    object edtCharacters: TEdit
      Left = 96
      Top = 62
      Width = 249
      Height = 21
      ReadOnly = True
      TabOrder = 4
    end
    object edtReceivePath: TEdit
      Left = 96
      Top = 35
      Width = 249
      Height = 21
      TabOrder = 5
    end
    object bSaveConfig: TButton
      Left = 560
      Top = 60
      Width = 71
      Height = 25
      Caption = 'Save'
      TabOrder = 6
      OnClick = bSaveConfigClick
    end
  end
  object mFile: TMemo
    Left = 4
    Top = 589
    Width = 281
    Height = 132
    TabOrder = 1
  end
  object mRecept: TMemo
    Left = 291
    Top = 589
    Width = 356
    Height = 132
    TabOrder = 2
  end
  object pcLIS: TPageControl
    Left = 0
    Top = 111
    Width = 656
    Height = 474
    ActivePage = tsSendRecept
    TabOrder = 3
    object tsSendRecept: TTabSheet
      Caption = 'Emission'
      object pSendData: TPanel
        Left = 3
        Top = 0
        Width = 597
        Height = 450
        BevelOuter = bvNone
        Color = clWhite
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
        object Label3: TLabel
          Left = 17
          Top = 8
          Width = 47
          Height = 16
          Caption = 'Patient'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label4: TLabel
          Left = 15
          Top = 107
          Width = 28
          Height = 16
          Caption = 'Test'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label9: TLabel
          Left = 24
          Top = 30
          Width = 48
          Height = 13
          Caption = 'Patient ID'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label2: TLabel
          Left = 24
          Top = 57
          Width = 64
          Height = 13
          Caption = 'Patient Name'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label10: TLabel
          Left = 24
          Top = 84
          Width = 64
          Height = 13
          Caption = 'P. First Name'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label11: TLabel
          Left = 299
          Top = 3
          Width = 77
          Height = 13
          Caption = 'P. Maiden Name'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label12: TLabel
          Left = 299
          Top = 30
          Width = 47
          Height = 13
          Caption = 'Birth date'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label13: TLabel
          Left = 299
          Top = 57
          Width = 18
          Height = 13
          Caption = 'Sex'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label14: TLabel
          Left = 299
          Top = 84
          Width = 58
          Height = 13
          Caption = 'Ethnic origin'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label15: TLabel
          Left = 22
          Top = 129
          Width = 48
          Height = 13
          Caption = 'Sample ID'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label16: TLabel
          Left = 24
          Top = 153
          Width = 21
          Height = 13
          Caption = 'Test'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label17: TLabel
          Left = 165
          Top = 153
          Width = 35
          Height = 13
          Caption = 'Dilution'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label18: TLabel
          Left = 220
          Top = 153
          Width = 22
          Height = 13
          Caption = 'Prev'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label19: TLabel
          Left = 363
          Top = 153
          Width = 24
          Height = 13
          Caption = 'Type'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label20: TLabel
          Left = 418
          Top = 153
          Width = 43
          Height = 13
          Caption = 'Sample T'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label21: TLabel
          Left = 473
          Top = 153
          Width = 12
          Height = 13
          Caption = 'ST'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label24: TLabel
          Left = 526
          Top = 153
          Width = 49
          Height = 13
          Caption = 'Tube type'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label26: TLabel
          Left = 253
          Top = 129
          Width = 180
          Height = 13
          Caption = #167' Chiffres uniquement pour tests trak'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object edtPatientID: TEdit
          Left = 112
          Top = 27
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object edtPatientName: TEdit
          Left = 112
          Top = 54
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object edtPatientFirstname: TEdit
          Left = 112
          Top = 81
          Width = 137
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object edtPatientMaidenName: TEdit
          Left = 387
          Top = 0
          Width = 137
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
        end
        object Edit5: TEdit
          Left = 387
          Top = 27
          Width = 137
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
        end
        object Edit6: TEdit
          Left = 387
          Top = 54
          Width = 137
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
        end
        object Edit7: TEdit
          Left = 387
          Top = 81
          Width = 137
          Height = 21
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
        end
        object edtSampleID: TEdit
          Left = 110
          Top = 126
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          MaxLength = 15
          ParentFont = False
          TabOrder = 7
          OnExit = edtSampleIDExit
        end
        object edtDilution1: TEdit
          Left = 165
          Top = 167
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          Text = '1'
        end
        object edtPrev1: TEdit
          Left = 220
          Top = 167
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 9
        end
        object edtST1: TEdit
          Left = 473
          Top = 167
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          TextHint = '1'
        end
        object edtTubeType1: TEdit
          Left = 526
          Top = 167
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 11
          Text = '1'
          TextHint = '1'
        end
        object bGenere: TButton
          Left = 24
          Top = 290
          Width = 137
          Height = 33
          Caption = 'Genere'
          TabOrder = 12
          OnClick = bGenereClick
        end
        object cbTest1: TComboBox
          Left = 22
          Top = 167
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ItemIndex = 0
          ParentFont = False
          TabOrder = 13
          Text = 'AFP'
          Items.Strings = (
            'AFP'
            'ANTITG'
            'ANTITPO'
            'CA125II'
            'CA153'
            'C1199'
            'CEA'
            'CGA'
            'CGAII'
            'CODAVP'
            'COPEPTIN'
            'COPEPTUS'
            'CRP'
            'CTPROAVP'
            'CTPROET1'
            'CYFRA211'
            'FBHCG'
            'FERRITIN'
            'FPSA'
            'HCG'
            'HTG'
            'HTG_RC5'
            'HTG_RC40'
            'KRYPT'
            'KRYPTON'
            'MRPROADM'
            'MRPROANP'
            'NSE'
            'OSTEO'
            'PAP'
            'PAPPA'
            'PCT'
            'PCTUS'
            'PLGF'
            'PLGFPLUS'
            'PROL'
            'PSA'
            'SCC'
            'SFLT1'
            'TGS'
            'TGS_R2_5'
            'TGS_R20'
            'TRAK'
            'TRAKTON')
        end
        object cbType1: TComboBox
          Left = 363
          Top = 167
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 14
          Text = 'R'
          Items.Strings = (
            'R'
            'A'
            'S')
        end
        object cbSampType1: TComboBox
          Left = 418
          Top = 167
          Width = 49
          Height = 21
          BiDiMode = bdLeftToRight
          ItemIndex = 0
          ParentBiDiMode = False
          TabOrder = 15
          Text = 'N'
          Items.Strings = (
            'N'
            'A'
            'Q')
        end
        object cbTest2: TComboBox
          Left = 22
          Top = 191
          Width = 137
          Height = 21
          TabOrder = 16
          Items.Strings = (
            'AFP'
            'ANTITG'
            'ANTITPO'
            'CA125II'
            'CA153'
            'C1199'
            'CEA'
            'CGA'
            'CGAII'
            'CODAVP'
            'COPEPTIN'
            'COPEPTUS'
            'CRP'
            'CTPROAVP'
            'CTPROET1'
            'CYFRA211'
            'FBHCG'
            'FERRITIN'
            'FPSA'
            'HCG'
            'HTG'
            'HTG_RC5'
            'HTG_RC40'
            'KRYPT'
            'KRYPTON'
            'MRPROADM'
            'MRPROANP'
            'NSE'
            'OSTEO'
            'PAP'
            'PAPPA'
            'PCT'
            'PCTUS'
            'PLGF'
            'PLGFPLUS'
            'PROL'
            'PSA'
            'SCC'
            'SFLT1'
            'TGS'
            'TGS_R2_5'
            'TGS_R20'
            'TRAK'
            'TRAKTON')
        end
        object edtDilution2: TEdit
          Left = 165
          Top = 191
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 17
          Text = '1'
        end
        object edtPrev2: TEdit
          Left = 220
          Top = 191
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 18
        end
        object cbType2: TComboBox
          Left = 363
          Top = 191
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 19
          Text = 'R'
          Items.Strings = (
            'R'
            'A'
            'S')
        end
        object cbSampType2: TComboBox
          Left = 418
          Top = 188
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 20
          Text = 'N'
          Items.Strings = (
            'N'
            'A'
            'Q')
        end
        object edtST2: TEdit
          Left = 473
          Top = 191
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 21
          Text = '1'
          TextHint = '1'
        end
        object edtTubeType2: TEdit
          Left = 526
          Top = 191
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 22
          Text = '1'
          TextHint = '1'
        end
        object cbTest3: TComboBox
          Left = 22
          Top = 215
          Width = 137
          Height = 21
          TabOrder = 23
          Items.Strings = (
            'AFP'
            'ANTITG'
            'ANTITPO'
            'CA125II'
            'CA153'
            'C1199'
            'CEA'
            'CGA'
            'CGAII'
            'CODAVP'
            'COPEPTIN'
            'COPEPTUS'
            'CRP'
            'CTPROAVP'
            'CTPROET1'
            'CYFRA211'
            'FBHCG'
            'FERRITIN'
            'FPSA'
            'HCG'
            'HTG'
            'HTG_RC5'
            'HTG_RC40'
            'KRYPT'
            'KRYPTON'
            'MRPROADM'
            'MRPROANP'
            'NSE'
            'OSTEO'
            'PAP'
            'PAPPA'
            'PCT'
            'PCTUS'
            'PLGF'
            'PLGFPLUS'
            'PROL'
            'PSA'
            'SCC'
            'SFLT1'
            'TGS'
            'TGS_R2_5'
            'TGS_R20'
            'TRAK'
            'TRAKTON')
        end
        object edtDilution3: TEdit
          Left = 165
          Top = 215
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 24
          Text = '1'
        end
        object edtPrev3: TEdit
          Left = 220
          Top = 215
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 25
        end
        object cbType3: TComboBox
          Left = 363
          Top = 215
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 26
          Text = 'R'
          Items.Strings = (
            'R'
            'A'
            'S')
        end
        object cbSampType3: TComboBox
          Left = 418
          Top = 215
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 27
          Text = 'N'
          Items.Strings = (
            'N'
            'A'
            'Q')
        end
        object edtST3: TEdit
          Left = 473
          Top = 215
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 28
          Text = '1'
          TextHint = '1'
        end
        object edtTubeType3: TEdit
          Left = 526
          Top = 215
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 29
          Text = '1'
          TextHint = '1'
        end
        object cbTest4: TComboBox
          Left = 22
          Top = 239
          Width = 137
          Height = 21
          TabOrder = 30
          Items.Strings = (
            'AFP'
            'ANTITG'
            'ANTITPO'
            'CA125II'
            'CA153'
            'C1199'
            'CEA'
            'CGA'
            'CGAII'
            'CODAVP'
            'COPEPTIN'
            'COPEPTUS'
            'CRP'
            'CTPROAVP'
            'CTPROET1'
            'CYFRA211'
            'FBHCG'
            'FERRITIN'
            'FPSA'
            'HCG'
            'HTG'
            'HTG_RC5'
            'HTG_RC40'
            'KRYPT'
            'KRYPTON'
            'MRPROADM'
            'MRPROANP'
            'NSE'
            'OSTEO'
            'PAP'
            'PAPPA'
            'PCT'
            'PCTUS'
            'PLGF'
            'PLGFPLUS'
            'PROL'
            'PSA'
            'SCC'
            'SFLT1'
            'TGS'
            'TGS_R2_5'
            'TGS_R20'
            'TRAK'
            'TRAKTON')
        end
        object edtDilution4: TEdit
          Left = 165
          Top = 239
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 31
          Text = '1'
        end
        object edtPrev4: TEdit
          Left = 220
          Top = 239
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 32
        end
        object cbType4: TComboBox
          Left = 363
          Top = 239
          Width = 49
          Height = 21
          BiDiMode = bdLeftToRight
          ItemIndex = 0
          ParentBiDiMode = False
          TabOrder = 33
          Text = 'R'
          Items.Strings = (
            'R'
            'A'
            'S')
        end
        object cbSampType4: TComboBox
          Left = 418
          Top = 239
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 34
          Text = 'N'
          Items.Strings = (
            'N'
            'A'
            'Q')
        end
        object edtST4: TEdit
          Left = 473
          Top = 239
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 35
          Text = '1'
          TextHint = '1'
        end
        object edtTubeType4: TEdit
          Left = 526
          Top = 239
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 36
          Text = '1'
          TextHint = '1'
        end
        object cbTest5: TComboBox
          Left = 22
          Top = 263
          Width = 137
          Height = 21
          TabOrder = 37
          Items.Strings = (
            'AFP'
            'ANTITG'
            'ANTITPO'
            'CA125II'
            'CA153'
            'C1199'
            'CEA'
            'CGA'
            'CGAII'
            'CODAVP'
            'COPEPTIN'
            'COPEPTUS'
            'CRP'
            'CTPROAVP'
            'CTPROET1'
            'CYFRA211'
            'FBHCG'
            'FERRITIN'
            'FPSA'
            'HCG'
            'HTG'
            'HTG_RC5'
            'HTG_RC40'
            'KRYPT'
            'KRYPTON'
            'MRPROADM'
            'MRPROANP'
            'NSE'
            'OSTEO'
            'PAP'
            'PAPPA'
            'PCT'
            'PCTUS'
            'PLGF'
            'PLGFPLUS'
            'PROL'
            'PSA'
            'SCC'
            'SFLT1'
            'TGS'
            'TGS_R2_5'
            'TGS_R20'
            'TRAK'
            'TRAKTON')
        end
        object edtDilution5: TEdit
          Left = 165
          Top = 263
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 38
          Text = '1'
        end
        object edtPrev5: TEdit
          Left = 220
          Top = 263
          Width = 137
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 39
        end
        object cbType5: TComboBox
          Left = 363
          Top = 263
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 40
          Text = 'R'
          Items.Strings = (
            'R'
            'A'
            'S')
        end
        object cbSampType5: TComboBox
          Left = 418
          Top = 263
          Width = 49
          Height = 21
          ItemIndex = 0
          TabOrder = 41
          Text = 'N'
          Items.Strings = (
            'N'
            'A'
            'Q')
        end
        object edtST5: TEdit
          Left = 473
          Top = 263
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 42
          Text = '1'
          TextHint = '1'
        end
        object edtTubeType5: TEdit
          Left = 526
          Top = 263
          Width = 49
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 43
          Text = '1'
          TextHint = '1'
        end
        object bSauveBD: TButton
          Left = 440
          Top = 290
          Width = 137
          Height = 33
          Caption = 'Sauve BD'
          TabOrder = 44
          Visible = False
          OnClick = bSauveBDClick
        end
        object seInit: TSpinEdit
          Left = 184
          Top = 290
          Width = 60
          Height = 22
          MaxValue = 0
          MinValue = 0
          TabOrder = 45
          Value = 0
        end
        object seNb: TSpinEdit
          Left = 264
          Top = 290
          Width = 60
          Height = 22
          MaxValue = 0
          MinValue = 0
          TabOrder = 46
          Value = 0
        end
        object bGenX: TButton
          Left = 332
          Top = 290
          Width = 82
          Height = 33
          Caption = 'Gen x'
          TabOrder = 47
          OnClick = bGenXClick
        end
        object pnlTrack: TPanel
          Left = 8
          Top = 336
          Width = 575
          Height = 89
          BevelOuter = bvNone
          Color = clActiveBorder
          ParentBackground = False
          TabOrder = 48
          object Label23: TLabel
            Left = 5
            Top = 12
            Width = 78
            Height = 13
            Caption = 'Nb Tests / Cycle'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object Label25: TLabel
            Left = 165
            Top = 12
            Width = 48
            Height = 13
            Caption = 'D'#233'lai (mn)'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object Label27: TLabel
            Left = 452
            Top = 12
            Width = 60
            Height = 13
            Caption = 'Tests Trak'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = [fsBold]
            ParentFont = False
          end
          object Label28: TLabel
            Left = 5
            Top = 36
            Width = 63
            Height = 13
            Caption = 'Nb Tests / ID'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object Label29: TLabel
            Left = 165
            Top = 36
            Width = 43
            Height = 13
            Caption = 'Restants'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object Label30: TLabel
            Left = 5
            Top = 60
            Width = 49
            Height = 13
            Caption = 'Max Tests'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object seTestsCycle: TSpinEdit
            Left = 89
            Top = 7
            Width = 60
            Height = 22
            MaxValue = 0
            MinValue = 0
            TabOrder = 0
            Value = 2
          end
          object seDelai: TSpinEdit
            Left = 219
            Top = 7
            Width = 60
            Height = 22
            MaxValue = 0
            MinValue = 0
            TabOrder = 1
            Value = 30
          end
          object bTestTrack: TButton
            Left = 324
            Top = 5
            Width = 122
            Height = 76
            Caption = 'Go'
            TabOrder = 2
            OnClick = bTestTrackClick
          end
          object sbNbTestID: TSpinEdit
            Left = 89
            Top = 31
            Width = 60
            Height = 22
            MaxValue = 0
            MinValue = 0
            TabOrder = 3
            Value = 2
          end
          object sbNbTestIDRestant: TSpinEdit
            Left = 219
            Top = 31
            Width = 60
            Height = 22
            MaxValue = 0
            MinValue = 0
            TabOrder = 4
            Value = 2
          end
          object seMaxTests: TSpinEdit
            Left = 89
            Top = 55
            Width = 60
            Height = 22
            MaxValue = 0
            MinValue = 0
            TabOrder = 5
            Value = 125
          end
        end
      end
    end
    object tsBD: TTabSheet
      Caption = 'Base de donn'#233'es'
      ImageIndex = 1
      TabVisible = False
      object sgBD: TStringGrid
        Left = 3
        Top = 32
        Width = 642
        Height = 411
        DefaultColWidth = 80
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
        TabOrder = 0
        ColWidths = (
          42
          97
          95
          145
          254)
      end
      object bInit: TButton
        Left = 3
        Top = 1
        Width = 71
        Height = 25
        Caption = 'Init'
        TabOrder = 1
        OnClick = bInitClick
      end
      object bSend: TButton
        Left = 574
        Top = 3
        Width = 71
        Height = 25
        Caption = 'Send'
        TabOrder = 2
        OnClick = bSendClick
      end
      object bDelete: TButton
        Left = 343
        Top = 1
        Width = 71
        Height = 25
        Caption = 'Delete'
        TabOrder = 3
        OnClick = bDeleteClick
      end
    end
    object tsJournal: TTabSheet
      Caption = 'Journal'
      ImageIndex = 2
      TabVisible = False
      object sgJournal: TStringGrid
        Left = 3
        Top = 32
        Width = 642
        Height = 289
        ColCount = 4
        DefaultColWidth = 80
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
        TabOrder = 0
        OnDblClick = sgJournalDblClick
        ColWidths = (
          119
          123
          22
          344)
      end
      object bInitJournal: TButton
        Left = 3
        Top = 1
        Width = 71
        Height = 25
        Caption = 'Init'
        TabOrder = 1
        OnClick = bInitJournalClick
      end
      object mArchive: TMemo
        Left = 3
        Top = 325
        Width = 356
        Height = 119
        TabOrder = 2
      end
    end
  end
  object tRecept: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = tReceptTimer
    Left = 360
    Top = 8
  end
  object TTrack: TTimer
    Enabled = False
    OnTimer = TTrackTimer
    Left = 560
    Top = 480
  end
end
