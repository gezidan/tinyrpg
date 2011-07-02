#ifndef ORG_HXX
#define ORG_HXX

#include<string>
#include<stdint.h>
#include<sstream> 
#include<iostream> 

#include "Ren.hxx"

/** Character class 
TODO -> Skills 
*/
class Org {
public:
  Org(); 
  ~Org(); 
  
  // For display 
  std::string getName() const; 
  unsigned int getAttack() const; 
  unsigned int getDefense() const;
  unsigned int getStamina() const; 
  unsigned int getHitpoints() const;
  unsigned int getSpeed() const; 
  unsigned char getClass() const; 
  unsigned char getAlly() const; 
  unsigned char getDistortion() const; 
  uint64_t getExperience() const; 

  // For standard setting 
  void setAttack(unsigned int); 
  void setDefense(unsigned int);
  void setStamina(unsigned int);
  void setHitpoints(unsigned int);
  void setName(std::string); 
  void setSpeed(unsigned int); 
  void setClass(unsigned char);
  void setAlly(unsigned char);
  void setDistortion(unsigned char); 

  // For battle stuffs (modifiers added) 
  unsigned int attack(); 
  unsigned int defend(); 
  void receiveDamage(unsigned int, Org&); 
  void receiveExperience(uint64_t); 
  size_t examineOrgList(const std::vector<Org*>&) const; 

  // aug is for augment 
  void augmentAttack(); 
  void augmentDefense(); 
  void augmentStamina(); 
  void augmentClass(); 

  // utilities 
  std::string to_s();
  std::string to_ms(); 
  void rand(); 
  void debug(); 
private:
  std::string mName; 
  unsigned int mAttack; 
  unsigned int mDefense; 
  unsigned int mStamina; 
  unsigned int mHitpoints; 
  unsigned int mSpeed;
  unsigned char mClass; /** Rogue, Warrior, Whatever */ 
  unsigned char mAlly; /** To classify who's side someone's on */
  unsigned char mDistortion; /** percentage to distort an attack up or down. */
  uint64_t mExperience; /** Experience gained from battles */

  // functions
  void augment(unsigned int); 
  void augment_special(); 

  Ren mRen; /** This to be used whenever we need to call upon randomness. Prevents bad seeds. */
};

#endif 

