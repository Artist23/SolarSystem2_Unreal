// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemGameModeBase.h"
#include "Paths.h"
void  ASolarSystemGameModeBase::CreateXmlParser()
{
	//������xml�ļ����ݣ���Ҫ����xml�Ĺ��򣬲��������޷�д��
	const FString _XmlContent = "<DocumentElement>\n<Infor>\n< ID>01 </ID >\n<Name>AB</Name>\n<Content>BCD</Content>\n</Infor>\n</DocumentElement>";
	//��Buffer�ķ�ʽ����һ��XmlFile����
	FXmlFile* _WriteXml = new FXmlFile(_XmlContent, EConstructMethod::ConstructFromBuffer);
	//����XmlFile����ʧ��
	if (_WriteXml == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("����xml�ļ�ʧ�ܣ�"));
		return;
	}
	//����xml�ļ�����ǰ����
	_WriteXml->Save(FPaths::GameDir() + "write01.xml");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("����xml�ļ��ɹ���"));
}

FString ASolarSystemGameModeBase::ReadXmlParser(const FString &XmlPath, const FString &target)
{

	FXmlFile* XmlFile = NULL;  //create a XML file
	XmlFile = new FXmlFile(XmlPath);
	if (XmlFile == NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Filed getting xmlfile"));
		return "";
	}
	
	FXmlNode* RootNode = NULL;//get the root node
	RootNode = XmlFile->GetRootNode();
	if (RootNode == NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Filed getting root node"));
		return "";
	}
	FXmlNode* targetNode = RootNode->FindChildNode(target); //find the target node
	FString targetContent = targetNode->GetContent();   //get inner content
	
	return targetContent.Replace(TEXT("(&#x000A;)"), TEXT("\r\n"));

}


