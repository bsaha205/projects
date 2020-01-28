--------------------------------------------------------
--  File created - Tuesday-December-22-2015   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ADDRESSES
--------------------------------------------------------

  CREATE TABLE "ADDRESSES" 
   (	"ADDRESS_ID" NUMBER(10,0), 
	"HOUSE_NO" VARCHAR2(10), 
	"ROAD_NO" VARCHAR2(10), 
	"VILLAGE" VARCHAR2(15), 
	"POST_OFFICE" VARCHAR2(15), 
	"THANA" VARCHAR2(15), 
	"DISTRICT" VARCHAR2(15), 
	"STUDENT_ID" NUMBER(10,0), 
	"TEACHER_ID" NUMBER(10,0)
   ) ;
--------------------------------------------------------
--  DDL for Table CLASS
--------------------------------------------------------

  CREATE TABLE "CLASS" 
   (	"CLASS_ID" NUMBER(5,0), 
	"CLASS_NAME" VARCHAR2(10), 
	"MONTHLY_FEE" NUMBER(5,0), 
	"MONTHLY_FINE" NUMBER(5,0), 
	"NO_OF_STUDENTS" NUMBER(5,0)
   ) ;
--------------------------------------------------------
--  DDL for Table FEES
--------------------------------------------------------

  CREATE TABLE "FEES" 
   (	"BILL_NO" NUMBER(10,0), 
	"PAYMENT_DATE" DATE, 
	"MONTH_PAID" NUMBER(15,0), 
	"STUDENT_ID" NUMBER(10,0), 
	"DUE" NUMBER(5,0)
   ) ;
--------------------------------------------------------
--  DDL for Table GENSUBJECT
--------------------------------------------------------

  CREATE TABLE "GENSUBJECT" 
   (	"SUBJECT_ID" NUMBER(5,0), 
	"SUBJECT_NAME" VARCHAR2(20)
   ) ;
--------------------------------------------------------
--  DDL for Table GRADES
--------------------------------------------------------

  CREATE TABLE "GRADES" 
   (	"GRADE_ID" NUMBER(10,0), 
	"GRADE_POINT" NUMBER(10,3), 
	"MERIT_POSITION" NUMBER(5,0), 
	"STUDENT_ID" NUMBER(10,0), 
	"CLASS_ID" NUMBER(5,0)
   ) ;
--------------------------------------------------------
--  DDL for Table SECTION
--------------------------------------------------------

  CREATE TABLE "SECTION" 
   (	"SECTION_ID" NUMBER(5,0), 
	"CLASS_ID" NUMBER(5,0), 
	"SECTION_NAME" VARCHAR2(10), 
	"ROOM_NO" NUMBER(5,0), 
	"NO_OF_STUDENTS" NUMBER(5,0)
   ) ;
--------------------------------------------------------
--  DDL for Table STUDENTS
--------------------------------------------------------

  CREATE TABLE "STUDENTS" 
   (	"STUDENT_ID" NUMBER(10,0), 
	"FIRST_NAME" VARCHAR2(15), 
	"LAST_NAME" VARCHAR2(15), 
	"BIRTH_DATE" DATE, 
	"GENDER" VARCHAR2(8), 
	"SECTION_ID" NUMBER(5,0), 
	"CLASS_ID" NUMBER(5,0), 
	"ROLL" NUMBER(5,0)
   ) ;
--------------------------------------------------------
--  DDL for Table SUBJECT
--------------------------------------------------------

  CREATE TABLE "SUBJECT" 
   (	"SUBJECT_ID" NUMBER(5,0), 
	"SECTION_ID" NUMBER(5,0), 
	"CLASS_ID" NUMBER(5,0), 
	"SUBJECT_NAME" VARCHAR2(15), 
	"CLASS_TIME" VARCHAR2(10), 
	"TEACHER_ID" NUMBER(10,0)
   ) ;
--------------------------------------------------------
--  DDL for Table TEACHERS
--------------------------------------------------------

  CREATE TABLE "TEACHERS" 
   (	"TEACHER_ID" NUMBER(10,0), 
	"FIRST_NAME" VARCHAR2(15), 
	"LAST_NAME" VARCHAR2(15), 
	"JOIN_DATE" DATE, 
	"GENDER" VARCHAR2(8), 
	"POSITION" VARCHAR2(20), 
	"POS_VAL" NUMBER(5,0)
   ) ;
--------------------------------------------------------
--  DDL for Table USERS
--------------------------------------------------------

  CREATE TABLE "USERS" 
   (	"USERNAME" VARCHAR2(20), 
	"PASSWORD" VARCHAR2(20)
   ) ;
--------------------------------------------------------
--  Constraints for Table STUDENTS
--------------------------------------------------------

  ALTER TABLE "STUDENTS" ADD CONSTRAINT "STD_PK" PRIMARY KEY ("STUDENT_ID") ENABLE;
 
  ALTER TABLE "STUDENTS" ADD CONSTRAINT "STD_UNQ" UNIQUE ("SECTION_ID", "CLASS_ID", "ROLL") ENABLE;
 
  ALTER TABLE "STUDENTS" MODIFY ("FIRST_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "STUDENTS" MODIFY ("LAST_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "STUDENTS" MODIFY ("SECTION_ID" NOT NULL ENABLE);
 
  ALTER TABLE "STUDENTS" MODIFY ("CLASS_ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table SECTION
--------------------------------------------------------

  ALTER TABLE "SECTION" ADD CONSTRAINT "Room_Un" UNIQUE ("ROOM_NO") ENABLE;
 
  ALTER TABLE "SECTION" MODIFY ("SECTION_ID" NOT NULL ENABLE);
 
  ALTER TABLE "SECTION" MODIFY ("CLASS_ID" NOT NULL ENABLE);
 
  ALTER TABLE "SECTION" MODIFY ("SECTION_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "SECTION" ADD CONSTRAINT "SYS_C0011408" PRIMARY KEY ("SECTION_ID", "CLASS_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table SUBJECT
--------------------------------------------------------

  ALTER TABLE "SUBJECT" MODIFY ("SUBJECT_ID" NOT NULL ENABLE);
 
  ALTER TABLE "SUBJECT" MODIFY ("SECTION_ID" NOT NULL ENABLE);
 
  ALTER TABLE "SUBJECT" MODIFY ("CLASS_ID" NOT NULL ENABLE);
 
  ALTER TABLE "SUBJECT" MODIFY ("SUBJECT_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "SUBJECT" ADD CONSTRAINT "SYS_C0011409" PRIMARY KEY ("SUBJECT_ID", "SECTION_ID", "CLASS_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table CLASS
--------------------------------------------------------

  ALTER TABLE "CLASS" ADD CONSTRAINT "CLASSCONST" CHECK (CLASS_ID>5 AND CLASS_ID<11) ENABLE;
 
  ALTER TABLE "CLASS" MODIFY ("CLASS_ID" NOT NULL ENABLE);
 
  ALTER TABLE "CLASS" MODIFY ("CLASS_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "CLASS" ADD CHECK ("CLASS_ID" IS NOT NULL) ENABLE;
 
  ALTER TABLE "CLASS" ADD CHECK ("CLASS_NAME" IS NOT NULL) ENABLE;
 
  ALTER TABLE "CLASS" ADD PRIMARY KEY ("CLASS_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table GENSUBJECT
--------------------------------------------------------

  ALTER TABLE "GENSUBJECT" ADD CONSTRAINT "SNAME_UNQ" UNIQUE ("SUBJECT_NAME") ENABLE;
 
  ALTER TABLE "GENSUBJECT" MODIFY ("SUBJECT_ID" NOT NULL ENABLE);
 
  ALTER TABLE "GENSUBJECT" MODIFY ("SUBJECT_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "GENSUBJECT" ADD PRIMARY KEY ("SUBJECT_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table TEACHERS
--------------------------------------------------------

  ALTER TABLE "TEACHERS" MODIFY ("TEACHER_ID" NOT NULL ENABLE);
 
  ALTER TABLE "TEACHERS" MODIFY ("FIRST_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "TEACHERS" MODIFY ("LAST_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "TEACHERS" MODIFY ("JOIN_DATE" NOT NULL ENABLE);
 
  ALTER TABLE "TEACHERS" MODIFY ("GENDER" NOT NULL ENABLE);
 
  ALTER TABLE "TEACHERS" MODIFY ("POSITION" NOT NULL ENABLE);
 
  ALTER TABLE "TEACHERS" ADD PRIMARY KEY ("TEACHER_ID") ENABLE;
 
  ALTER TABLE "TEACHERS" MODIFY ("POS_VAL" NOT NULL ENABLE);
 
  ALTER TABLE "TEACHERS" ADD CONSTRAINT "TEACH_UNQ" UNIQUE ("FIRST_NAME", "LAST_NAME") ENABLE;
--------------------------------------------------------
--  Constraints for Table USERS
--------------------------------------------------------

  ALTER TABLE "USERS" MODIFY ("USERNAME" NOT NULL ENABLE);
 
  ALTER TABLE "USERS" MODIFY ("PASSWORD" NOT NULL ENABLE);
 
  ALTER TABLE "USERS" ADD PRIMARY KEY ("USERNAME") ENABLE;
--------------------------------------------------------
--  Constraints for Table FEES
--------------------------------------------------------

  ALTER TABLE "FEES" MODIFY ("BILL_NO" NOT NULL ENABLE);
 
  ALTER TABLE "FEES" MODIFY ("STUDENT_ID" NOT NULL ENABLE);
 
  ALTER TABLE "FEES" ADD PRIMARY KEY ("BILL_NO") ENABLE;
--------------------------------------------------------
--  Constraints for Table ADDRESSES
--------------------------------------------------------

  ALTER TABLE "ADDRESSES" ADD CONSTRAINT "STID_UN" UNIQUE ("STUDENT_ID") ENABLE;
 
  ALTER TABLE "ADDRESSES" MODIFY ("ADDRESS_ID" NOT NULL ENABLE);
 
  ALTER TABLE "ADDRESSES" ADD PRIMARY KEY ("ADDRESS_ID") ENABLE;
 
  ALTER TABLE "ADDRESSES" ADD CONSTRAINT "TEACH_UN" UNIQUE ("TEACHER_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table GRADES
--------------------------------------------------------

  ALTER TABLE "GRADES" ADD CONSTRAINT "CLASTUD_UN" UNIQUE ("STUDENT_ID", "CLASS_ID") ENABLE;
 
  ALTER TABLE "GRADES" MODIFY ("GRADE_ID" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" MODIFY ("GRADE_POINT" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" MODIFY ("MERIT_POSITION" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" MODIFY ("STUDENT_ID" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" ADD PRIMARY KEY ("GRADE_ID") ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("GRADE_ID" IS NOT NULL) ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("GRADE_POINT" IS NOT NULL) ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("MERIT_POSITION" IS NOT NULL) ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("STUDENT_ID" IS NOT NULL) ENABLE;
--------------------------------------------------------
--  DDL for Index SNAME_UNQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "SNAME_UNQ" ON "GENSUBJECT" ("SUBJECT_NAME") 
  ;
--------------------------------------------------------
--  DDL for Index TEACH_UNQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "TEACH_UNQ" ON "TEACHERS" ("FIRST_NAME", "LAST_NAME") 
  ;
--------------------------------------------------------
--  DDL for Index CLASTUD_UN
--------------------------------------------------------

  CREATE UNIQUE INDEX "CLASTUD_UN" ON "GRADES" ("STUDENT_ID", "CLASS_ID") 
  ;
--------------------------------------------------------
--  DDL for Index STD_UNQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "STD_UNQ" ON "STUDENTS" ("SECTION_ID", "CLASS_ID", "ROLL") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C0011409
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C0011409" ON "SUBJECT" ("SUBJECT_ID", "SECTION_ID", "CLASS_ID") 
  ;
--------------------------------------------------------
--  DDL for Index STD_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "STD_PK" ON "STUDENTS" ("STUDENT_ID") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C0011408
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C0011408" ON "SECTION" ("SECTION_ID", "CLASS_ID") 
  ;
--------------------------------------------------------
--  DDL for Index STID_UN
--------------------------------------------------------

  CREATE UNIQUE INDEX "STID_UN" ON "ADDRESSES" ("STUDENT_ID") 
  ;
--------------------------------------------------------
--  DDL for Index TEACH_UN
--------------------------------------------------------

  CREATE UNIQUE INDEX "TEACH_UN" ON "ADDRESSES" ("TEACHER_ID") 
  ;
--------------------------------------------------------
--  DDL for Index Room_Un
--------------------------------------------------------

  CREATE UNIQUE INDEX "Room_Un" ON "SECTION" ("ROOM_NO") 
  ;
--------------------------------------------------------
--  Ref Constraints for Table ADDRESSES
--------------------------------------------------------

  ALTER TABLE "ADDRESSES" ADD CONSTRAINT "STDD_ID" FOREIGN KEY ("STUDENT_ID")
	  REFERENCES "STUDENTS" ("STUDENT_ID") ON DELETE CASCADE ENABLE;
 
  ALTER TABLE "ADDRESSES" ADD CONSTRAINT "TEACH_ID" FOREIGN KEY ("TEACHER_ID")
	  REFERENCES "TEACHERS" ("TEACHER_ID") ON DELETE CASCADE ENABLE;

--------------------------------------------------------
--  Ref Constraints for Table FEES
--------------------------------------------------------

  ALTER TABLE "FEES" ADD CONSTRAINT "STD_ID" FOREIGN KEY ("STUDENT_ID")
	  REFERENCES "STUDENTS" ("STUDENT_ID") ON DELETE CASCADE ENABLE;

--------------------------------------------------------
--  Ref Constraints for Table GRADES
--------------------------------------------------------

  ALTER TABLE "GRADES" ADD CONSTRAINT "CLL_FK" FOREIGN KEY ("CLASS_ID")
	  REFERENCES "CLASS" ("CLASS_ID") ON DELETE CASCADE ENABLE;
 
  ALTER TABLE "GRADES" ADD CONSTRAINT "ST_ID" FOREIGN KEY ("STUDENT_ID")
	  REFERENCES "STUDENTS" ("STUDENT_ID") ON DELETE CASCADE ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table SECTION
--------------------------------------------------------

  ALTER TABLE "SECTION" ADD CONSTRAINT "CLS_ID" FOREIGN KEY ("CLASS_ID")
	  REFERENCES "CLASS" ("CLASS_ID") ON DELETE CASCADE ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table STUDENTS
--------------------------------------------------------

  ALTER TABLE "STUDENTS" ADD CONSTRAINT "SEC_FK" FOREIGN KEY ("SECTION_ID", "CLASS_ID")
	  REFERENCES "SECTION" ("SECTION_ID", "CLASS_ID") ON DELETE CASCADE ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table SUBJECT
--------------------------------------------------------

  ALTER TABLE "SUBJECT" ADD CONSTRAINT "SECLS_FK" FOREIGN KEY ("SECTION_ID", "CLASS_ID")
	  REFERENCES "SECTION" ("SECTION_ID", "CLASS_ID") ON DELETE CASCADE ENABLE;
 
  ALTER TABLE "SUBJECT" ADD CONSTRAINT "SUB_FK" FOREIGN KEY ("SUBJECT_ID")
	  REFERENCES "GENSUBJECT" ("SUBJECT_ID") ON DELETE CASCADE ENABLE;
 
  ALTER TABLE "SUBJECT" ADD CONSTRAINT "TEAC_FK" FOREIGN KEY ("TEACHER_ID")
	  REFERENCES "TEACHERS" ("TEACHER_ID") ON DELETE SET NULL ENABLE;


--------------------------------------------------------
--  DDL for Trigger CLASS_CONS
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "CLASS_CONS" 
BEFORE INSERT ON CLASS
DECLARE 
NUM NUMBER(5);
BEGIN
SELECT COUNT(*) INTO NUM FROM CLASS;
    if NUM>4
  then raise_application_error(-20001,'THIS CLASS CAN NOT BE STORED');
  end if;
END;


/
ALTER TRIGGER "CLASS_CONS" ENABLE;
--------------------------------------------------------
--  DDL for Trigger STCOUNT_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "STCOUNT_TRIGGER" 
AFTER INSERT OR DELETE ON STUDENTS
DECLARE
CURSOR stcursor IS
    SELECT class_id, count(*) from students group by class_id;
  clss students.class_id%type;
  num NUMBER;

BEGIN
  
  open stcursor;
  fetch stcursor into clss, num;
  while stcursor%found loop
    update class set no_of_students=num where class_id=clss;
    fetch stcursor into clss, num;
  end loop;
  
END;


/
ALTER TRIGGER "STCOUNT_TRIGGER" ENABLE;
--------------------------------------------------------
--  DDL for Function MERIT_POS
--------------------------------------------------------

  CREATE OR REPLACE FUNCTION "MERIT_POS" (ST_ID IN NUMBER, CL_ID IN NUMBER, GP IN FLOAT) RETURN NUMBER AS
MPOS NUMBER;
BEGIN
  SELECT COUNT(G1.STUDENT_ID) INTO MPOS
  FROM GRADES G1
  WHERE (GP<G1.GRADE_POINT AND CL_ID=G1.CLASS_ID);
  RETURN (MPOS);
END merit_pos;

/

