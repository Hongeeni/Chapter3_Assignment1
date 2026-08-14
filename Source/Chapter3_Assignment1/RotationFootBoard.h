#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationFootBoard.generated.h"

UCLASS()
class CHAPTER3_ASSIGNMENT1_API ARotationFootBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationFootBoard();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item/Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item/Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Item/Properties")
	FVector ObjectLocation = FVector::ZeroVector;
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Item/Properties")
	FRotator ObjectRotation = FRotator::ZeroRotator;
	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = "Item/Properties")
	FVector ObjectScale = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item/Properties")
	float RotationSpeed = 100.0f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ResetActorPosition();
};
