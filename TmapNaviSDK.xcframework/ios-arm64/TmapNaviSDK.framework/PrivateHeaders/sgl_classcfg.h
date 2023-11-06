// sglclasscfg.h

// �ۼ��� : ������
// �ۼ��� : 2007.12.27
// ��  �� : Ŭ���� Ư�� ���� ��ũ��

#ifndef __SGLCLASSCFG_H
#define __SGLCLASSCFG_H

#define NOT_COPYABLE(class_name)							\
private :													\
	class_name(const class_name&);							\
	class_name& operator=(const class_name&);

#define NOT_INSTANCE(class_name)							\
private :													\
	class_name() {}											\
	~class_name() {}

#endif // __SGLCLASSCFG_H
