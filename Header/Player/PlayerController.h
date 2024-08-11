#pragma once
namespace Player {
	enum class BulletType {
		Point,
		Area
	};
	class PlayerModel;
	class PlayerView;
	class PlayerController {
	private:
		PlayerModel* playerModel;

		BulletType bulletType = BulletType::Point;
		//PlayerView* playerView ;
		void create();
		void destroy();
		void processPlayerInput();
		void reduceAmmo();
		void checkIfDuckUnderCursor();
		
	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		void reset();

		void reduceHealth();
		int getHealth();

		void restAmmoPerRound();
		int getAmmoPerRound();
		int getRadiusAmmoPerRound();

		int getScore();
		void increaseScore(int increaseAmount);
		void increaseAmmo();

		BulletType getBulletType();
		void setBulletType(BulletType type);
	};
	
}