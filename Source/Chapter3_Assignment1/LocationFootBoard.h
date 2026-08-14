#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocationFootBoard.generated.h"

UCLASS()
class CHAPTER3_ASSIGNMENT1_API ALocationFootBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	ALocationFootBoard();

protected:
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
