// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarSystemGameModeBase.h"
#include "Paths.h"
void  ASolarSystemGameModeBase::CreateXmlParser()
{
	//创建的xml文件内容，需要符合xml的规则，不符合则无法写入
	const FString _XmlContent = "<DocumentElement>\n<Infor>\n< ID>01 </ID >\n<Name>AB</Name>\n<Content>BCD</Content>\n</Infor>\n</DocumentElement>";
	//以Buffer的方式创建一个XmlFile对象
	FXmlFile* _WriteXml = new FXmlFile(_XmlContent, EConstructMethod::ConstructFromBuffer);
	//创建XmlFile对象失败
	if (_WriteXml == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("创建xml文件失败！"));
		return;
	}
	//保存xml文件到当前工程
	_WriteXml->Save(FPaths::GameDir() + "write01.xml");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("创建xml文件成功！"));
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


