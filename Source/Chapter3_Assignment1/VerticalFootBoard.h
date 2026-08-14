#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VerticalFootBoard.generated.h"

UCLASS()
class CHAPTER3_ASSIGNMENT1_API AVerticalFootBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	AVerticalFootBoard();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item/Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item/Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Item/Properties")
	FVector StartLocation = FVector::ZeroVector;
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Item/Properties")
	FRotator ObjectRotation = FRotator::ZeroRotator;
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Item/Properties")
	FVector ObjectScale = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item/Properties")
	float LocationMaxRange = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item/Properties")
	float MoveSpeed = 100.0;
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Item/Properties")
	bool IsTurn = false;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ResetActorPosition();
};
