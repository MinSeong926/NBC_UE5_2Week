#include "Shotgun.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

AShotgun::AShotgun()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AShotgun::FireShotgun()
{
	if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
	{
		if (APlayerController* PC = Cast<APlayerController>(OwnerPawn->GetController()))
		{
			// 뷰포트 출력
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("반동!!"));
			}

			// 로그 출력
			UE_LOG(LogTemp, Warning, TEXT("반동!!"));

			FVector CameraLocation;
			FRotator CameraRotation;
			PC->GetPlayerViewPoint(CameraLocation, CameraRotation);

			FVector ForwardVector = CameraRotation.Vector();

			// 샷건의 실제 위치 가져오기
			FVector GunLocation = GetActorLocation();

			for (int32 i = 0; i < PelletCount; i++)
			{
				float HalfAngleRad = FMath::DegreesToRadians(SpreadAngle / 2.0f);

				FVector ShootDirection = FMath::VRandCone(ForwardVector, HalfAngleRad);
				FVector EndLocation = CameraLocation + (ShootDirection * 5000.0f);

				FHitResult HitResult;
				FCollisionQueryParams CollisionParams;
				CollisionParams.AddIgnoredActor(OwnerPawn);
				CollisionParams.AddIgnoredActor(this);

				bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, CameraLocation, EndLocation, ECC_Visibility, CollisionParams);

				// 시각적 선 그리기 (출발점을 CameraLocation에서 GunLocation으로 변경)
				if (bHit)
				{
					DrawDebugLine(GetWorld(), GunLocation, HitResult.ImpactPoint, FColor::Red, false, 2.0f);
				}
				else
				{
					DrawDebugLine(GetWorld(), GunLocation, EndLocation, FColor::Green, false, 2.0f);
				}
			}

			float RandomYaw = FMath::RandRange(-RecoilYawRange, RecoilYawRange);

			PC->AddPitchInput(RecoilPitchAmount);
			PC->AddYawInput(RandomYaw);
		}
	}
}