#include "VerticalFootBoard.h"

AVerticalFootBoard::AVerticalFootBoard()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Resources/Shapes/Shape_WideCapsule.Shape_WideCapsule"));
	if (MeshAsset.Succeeded()) {
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Resources/Materials/M_Ground_Grass.M_Ground_Grass"));
	if (MaterialAsset.Succeeded()) {
		StaticMesh->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
}

void AVerticalFootBoard::BeginPlay() {
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	ObjectRotation = GetActorRotation();
	ObjectScale = GetActorScale3D();

	ResetActorPosition();
}

void AVerticalFootBoard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	FVector DeltaLocation = GetActorUpVector() * MoveSpeed * DeltaTime;
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

void AVerticalFootBoard::ResetActorPosition() {
	SetActorTransform(FTransform(ObjectRotation, StartLocation, ObjectScale));
}