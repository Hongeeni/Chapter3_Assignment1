#include "LocationFootBoard.h"

ALocationFootBoard::ALocationFootBoard()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Resources/Shapes/Shape_WideCapsule.Shape_WideCapsule"));
	if (MeshAsset.Succeeded()) {
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Rust.M_Metal_Rust"));
	if (MaterialAsset.Succeeded()) {
		StaticMesh->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
}

void ALocationFootBoard::BeginPlay() {
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	ObjectRotation = GetActorRotation();
	ObjectScale = GetActorScale3D();

	ResetActorPosition();
}

void ALocationFootBoard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	FVector DeltaLocation = GetActorForwardVector() * MoveSpeed * DeltaTime;
	float Distance = (StartLocation - GetActorLocation()).Length();

	if (!FMath::IsNearlyZero(MoveSpeed)) {
		if (IsTurn && Distance < LocationMaxRange) {
			IsTurn = false;
		}
		else if (!IsTurn && Distance >= LocationMaxRange) {
			IsTurn = true;
			MoveSpeed *= -1.0f;
		}
		AddActorLocalOffset(DeltaLocation);
	}
}

void ALocationFootBoard::ResetActorPosition() {
	SetActorTransform(FTransform(ObjectRotation, StartLocation, ObjectScale));
}