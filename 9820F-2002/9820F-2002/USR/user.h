//==========================================================
//�ļ����ƣ�User.h
//�����������û���������ͷ�ļ�
//�ļ��汾��Ver1.0
//�������ڣ�2014.12.15
//�޸����ڣ�2015.08.20 11:03
//�ļ���ע����
//==========================================================
#ifndef __User_H__
#define __User_H__

//==========================================================
//��������ʾλ�ö���
#define SETUP_ADDR_X		(6)
#define SETUP_ADDR_Y		(27)
#define HEIGHT_OF_SETUP		(20)

//��˸���
#define CURSORCHAR (' ')

////�˵������ı���󳤶�(12���ַ�)
//#define MENU_MAX_TEXT_LEN (12)
//
////ÿҳ�˵������ֵ
////#define MENU_LIST_MAX_PAGE_INDEX (10)
//#define MENU_LIST_MAX_PAGE_INDEX (12)
////X��˵�����
//#define MENU_LIST_X_INDEX (2)
////Y��˵�����
////#define MENU_LIST_Y_INDEX (MENU_LIST_MAX_PAGE_INDEX/MENU_LIST_X_INDEX-1)
//#define MENU_LIST_Y_INDEX (MENU_LIST_MAX_PAGE_INDEX/MENU_LIST_X_INDEX)
//
////ϵͳ����,Y��˵�����
//#define SYSTEM_MENU_LIST_Y_INDEX (MENU_LIST_Y_INDEX-2)

//����λ��˸ʱ�䣬1000/3=333mS
#define BLINK_TICKS_SOFTTIMER (TICKS_PER_SEC_SOFTTIMER/3)
extern const u32 RANGE_RATE[5];
extern const u8 MsgTab[][6+1];//ϵͳ״̬

//==========================================================
//���ӡ�����
//extern const u16 POW_NUM[4];

////==========================================================
////��������ֵ�ϡ����ޡ�С����
//extern const u16 SetupLimit[][8][2];

////==========================================================
////��������ֵС����λ
//extern const u8 ParameterDotTab[][PARAMETER_MENU_MAX];

////==========================================================
////���
//extern const u8 NumTab[][3];

////==========================================================
////��Ŀ
//extern const u8 ItemTab[][9];
//extern const u8 ItemCharTab[][3];

//==========================================================
//�����б�
void Hex_Format(u16 dat , u8 dot , u8 len, bool dispzero);//��ʽ��Hex��Bcd�ַ�����DispBuf
void Disp_SysMessage(void);
void Disp_PowerOn_Menu(void);
void Check_Parameter_Limit(void);
void Range_Control(u8 dat);
void Parameter_Setup(void);
void Disp_Setup_Menu(u8 index);
void System_Setup(void);

void Range_Changecomp(void);
void Get_FFT(void);
void Test_Debug(void);
void _4094_data(void);
void InitGlobalValue(void);
void Parameter_valuecomp(void);
u16 Da_out(u16 v_value,u8 V_range);
void DispF(float f);
void Get_Res(void);
void Comp_test(u16 comp_data);
void Dma_Int(void);
void Disp_TestMessage(void);
u32 jisuandianzu(u16 bzdzn,u16 bzdzadn,u16 I_ad,u16 V_ad,u16 bzdy);
//u8 Resistance_Setup(NumBox_TypeDef * pt);
//u8 ListBox_Setup(NumBox_TypeDef * pt);
//u8 Number_Setup(NumBox_TypeDef * pt);//��ֵ������
//u8 ListBox_Setup(NumBox_TypeDef * pt);//�б������

////void Disp_Kjjm( void );//��ʾ��������
//void Disp_PowerOn_Menu(void);//��ʾ��������

//void Disp_Group(u8 highlight);//��ʾ���
//void Disp_Frame(void);//��ʾ������

//void Disp_Idle_List(void);//��ʾ�����˵��б�
void Disp_Idle_Menu(void);//��ʾ��������
//void Disp_Idle_Info(void);//��ʾ������Ϣ

void Step_Setup(void);//�������ô���
void BCDtoHex(u8 *pBuff,u8 len);
u8 BCDtoHex1(u8 pBuff,u8 len);
//void Disp_Step_Menu(void);//��ʾ����˵�
//void Disp_Step_Info(void);//��ʾ������Ϣ

//void Parameter_Setup(void);//�������ô���
//void Disp_Parameter_Menu(void);//��ʾ��������
//void Disp_Parameter_Info(u8 index);//��ʾ������Ϣ
//void Disp_Parameter_Value(u8 step ,u8 index, u8 highlight);//��ʾ�ڼ����ڼ������ֵ
//void Check_Parameter_Limit(u8 step);//����ֵ���
//void Check_Setup_Limit(void);//4������Ĳ���ֵ���

//void System_Setup(void);//ϵͳ���ô���
//void Disp_System_Menu(void);//��ʾϵͳ����
//void Disp_System_Info(u8 index);//��ʾϵͳ��Ϣ
//void Disp_System_Value(u8 index);//��ʾ�ڼ���ϵͳֵ
//void Check_System_Limit(void);//ϵͳֵ���

//void FactoryInfo_Setup(void);//������Ϣ���ô���
//void Disp_Factory_Info(void);//��ʾ������Ϣ
//void Disp_Software_Version(void);//��ʾ����汾
//void Disp_Hardware_Version(void);//��ʾӲ���汾
//void Disp_Boot_Number(void);//��ʾ��������
//void Disp_Compile_Date(void);//��ʾ��������

//void Disp_Instrument_Info(void);//��ʾ������Ϣ
//void Disp_Chip_ID(void);//��ʾоƬID��
//void Disp_Product_ID(void);//��ʾ��Ʒ���	
//void Disp_Product_Model(void);//��ʾ��Ʒ�ͺ�
//void Disp_Company_Name(void);//��ʾ��������
//void Disp_Company_Telephone(void);//��ʾ���̵绰
//void Disp_Company_Http(void);//��ʾ������ҳ

//void Config_Setup(void);//�������ô���
//void Disp_Config_Menu(void);//��ʾ���ý���
//void Disp_Config_Value(u8 index);//��ʾ����ֵ
//void Check_Config_Limit(void);//����ֵ���

//void Password_Setup(void);//��������
//Bool Password_Check(void);//����У��,TRUE��Ч

////==========================================================
////void Disp_SysStatus(void);//��ʾϵͳ״̬
//void Disp_SysMessage(void);//��ʾϵͳ��Ϣ


//==========================================================


#endif

//==========================================================
//END
//==========================================================
