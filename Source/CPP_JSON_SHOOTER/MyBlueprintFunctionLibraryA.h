// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibraryA.generated.h"

USTRUCT(BlueprintType)
struct FAverages
{
	FAverages() : Mean(0.0f), Modal(0.0f), Median(0.0f)
	{

	};

	FAverages(float inMean, float inMode, float inMedian) :
		Mean(inMean),
		Modal(inMode),
		Median(inMedian)
	{

	};

	UPROPERTY(BlueprintReadOnly)
	float Mean = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float Median = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float Modal = 0.0f;

	GENERATED_BODY()
};
/**
 * 
 */
UCLASS()
class CPP_JSON_SHOOTER_API UMyBlueprintFunctionLibraryA : public UBlueprintFunctionLibrary
{
public:
	UFUNCTION(BlueprintCallable)
	static FString GetPointlessMessageSending();

	UFUNCTION(BlueprintCallable, 
			  BlueprintPure, 
			  meta = (ToolTip = "3.1415blehblehbleh...", CompactNodeTitle = "π"))
	
	static double GetPi();

	UFUNCTION(BlueprintCallable, meta = (ToolTip = "Calculate the mean, median and mode for an array of integer values. "))
	static FAverages CalculateAverages(const TArray<int32> &inValues);
	

private:
	static constexpr double pi = 3.1415;
	GENERATED_BODY()

	
};
