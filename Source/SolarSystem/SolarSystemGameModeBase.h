// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "XmlParser.h"
#include "SolarSystemGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SOLARSYSTEM_API ASolarSystemGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	//������д��xml�ļ�
	UFUNCTION(BlueprintCallable, Category = "Xml")
	void  CreateXmlParser();

	//��ȡxml�ļ�
	UFUNCTION(BlueprintCallable, Category = "Xml")
	static FString  ReadXmlParser(const FString &_XmlPath, const FString &_target);
};
