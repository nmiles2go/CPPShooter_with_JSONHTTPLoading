// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibraryA.h"

FString UMyBlueprintFunctionLibraryA::GetPointlessMessageSending()
{
	return FString(TEXT("This is stupid message!"));
}

double UMyBlueprintFunctionLibraryA::GetPi()
{
	return pi;
}

FAverages UMyBlueprintFunctionLibraryA::CalculateAverages(const TArray<int32>& inValues)
{
	/*duplicate the array as we dont want to mess with the original*/
	TArray<int32> TempArray = inValues;
	TMap<int32, int32> ModalCount;

	float calMean	{ 0.0f };
	float calMode	{ 0.0f };
	float calMedian	{ 0.0f };
	float Sum		{ 0 };
	const int32 Count = TempArray.Num();

	if (0 == Count) return FAverages(0.0f, 0.0f, 0.0f);

	TempArray.Sort();
	
	for (int i{ 0 }; i < Count; ++i)
	{
		Sum += TempArray[i];

		if (ModalCount.Contains(TempArray[i]))
		{
			ModalCount[TempArray[i]]++;
		}

		else
		{
			ModalCount.Add(TempArray[i], 1);
		}
	}

	calMean = Sum / static_cast<float>(Count);

	calMedian = Count % 2 != 0 
				? TempArray[Count / 2] 
				: static_cast<float>((TempArray[(Count / 2) - 1] + TempArray[Count / 2])) / 2;

	ModalCount.ValueSort([](int32 A, int32 B)
		{
			return A > B;
		});

	TArray<TPair<int32, int32>> Modals = ModalCount.Array();

	if (Modals[0].Value == 1)
	{
		calMode = calMean;
	}

	else
	{
		int32 ModalEntries{ 1 };
		int32 ModalSum = Modals[0].Key;

		for (int i{ 1 }; i < Modals.Num(); ++i)
		{
			if (Modals[i].Value != Modals[0].Value) break;
			ModalSum += Modals[i].Key;
			ModalEntries++;
		}

		calMode = static_cast<float>(ModalSum) / static_cast<float>(ModalEntries);
	}
	return FAverages(calMean, calMode, calMedian);
}
