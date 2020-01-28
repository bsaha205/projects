--------------------------------------------------------
--  File created - Wednesday-December-23-2015   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ADDRESSES
--------------------------------------------------------

  CREATE TABLE "ADDRESSES" 
   (	"ADDRESS_ID" NUMBER(10,0), 
	"HOUSE_NO" VARCHAR2(20), 
	"ROAD_NO" VARCHAR2(30), 
	"VILLAGE" VARCHAR2(20), 
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
	"SUBJECT_NAME" VARCHAR2(30)
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
	"SUBJECT_NAME" VARCHAR2(30), 
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

---------------------------------------------------
--   DATA FOR TABLE ADDRESSES
--   FILTER = none used
---------------------------------------------------
REM INSERTING into ADDRESSES
Insert into ADDRESSES (ADDRESS_ID,HOUSE_NO,ROAD_NO,VILLAGE,POST_OFFICE,THANA,DISTRICT,STUDENT_ID,TEACHER_ID) values (2,'4/7','4, FULBARI ROAD','FULPUR','KULBAN','MOHESHKHALI','CHITTAGONG',null,2);
Insert into ADDRESSES (ADDRESS_ID,HOUSE_NO,ROAD_NO,VILLAGE,POST_OFFICE,THANA,DISTRICT,STUDENT_ID,TEACHER_ID) values (3,'7/12','5, GOLAP ROAD','GOLPPUR','GOLAPGANJ','GOLAPDI','GOPALGANJ',null,5);
Insert into ADDRESSES (ADDRESS_ID,HOUSE_NO,ROAD_NO,VILLAGE,POST_OFFICE,THANA,DISTRICT,STUDENT_ID,TEACHER_ID) values (6,'45','55','SHANKARPUR','CHACHRA','KOTOALI','JESSORE',2,null);
Insert into ADDRESSES (ADDRESS_ID,HOUSE_NO,ROAD_NO,VILLAGE,POST_OFFICE,THANA,DISTRICT,STUDENT_ID,TEACHER_ID) values (1,'12/14','3,MRIDHA ROAD','TOLAGAON','MULGHAR','PANGSHA','RAJBARI',null,3);
Insert into ADDRESSES (ADDRESS_ID,HOUSE_NO,ROAD_NO,VILLAGE,POST_OFFICE,THANA,DISTRICT,STUDENT_ID,TEACHER_ID) values (4,'4/85','3. FULLER ROAD','FULTOLI','FULGANJ','TEJGAON','DHAKA',null,4);
Insert into ADDRESSES (ADDRESS_ID,HOUSE_NO,ROAD_NO,VILLAGE,POST_OFFICE,THANA,DISTRICT,STUDENT_ID,TEACHER_ID) values (5,'6','4','KOLAKHALI','KOLAKHALI','KOLAKHALI','KHULNA',1,null);
Insert into ADDRESSES (ADDRESS_ID,HOUSE_NO,ROAD_NO,VILLAGE,POST_OFFICE,THANA,DISTRICT,STUDENT_ID,TEACHER_ID) values (7,'55','44','GAIGAR','NURGAON','NURGAO','FARIDPUR',17,null);

---------------------------------------------------
--   END DATA FOR TABLE ADDRESSES
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE CLASS
--   FILTER = none used
---------------------------------------------------
REM INSERTING into CLASS
Insert into CLASS (CLASS_ID,CLASS_NAME,MONTHLY_FEE,MONTHLY_FINE,NO_OF_STUDENTS) values (6,'SIX',40,10,10);
Insert into CLASS (CLASS_ID,CLASS_NAME,MONTHLY_FEE,MONTHLY_FINE,NO_OF_STUDENTS) values (7,'SEVEN',40,12,10);
Insert into CLASS (CLASS_ID,CLASS_NAME,MONTHLY_FEE,MONTHLY_FINE,NO_OF_STUDENTS) values (8,'EIGHT',50,12,10);
Insert into CLASS (CLASS_ID,CLASS_NAME,MONTHLY_FEE,MONTHLY_FINE,NO_OF_STUDENTS) values (9,'NINE',50,15,null);
Insert into CLASS (CLASS_ID,CLASS_NAME,MONTHLY_FEE,MONTHLY_FINE,NO_OF_STUDENTS) values (10,'TEN',60,15,null);

---------------------------------------------------
--   END DATA FOR TABLE CLASS
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE FEES
--   FILTER = none used
---------------------------------------------------
REM INSERTING into FEES
Insert into FEES (BILL_NO,PAYMENT_DATE,MONTH_PAID,STUDENT_ID,DUE) values (3,to_timestamp('06-JUN-15 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),9,13,156);
Insert into FEES (BILL_NO,PAYMENT_DATE,MONTH_PAID,STUDENT_ID,DUE) values (1,to_timestamp('05-MAY-15 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),5,1,350);
Insert into FEES (BILL_NO,PAYMENT_DATE,MONTH_PAID,STUDENT_ID,DUE) values (2,to_timestamp('08-AUG-15 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),8,2,200);
Insert into FEES (BILL_NO,PAYMENT_DATE,MONTH_PAID,STUDENT_ID,DUE) values (4,to_timestamp('06-JUN-15 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),10,12,104);
Insert into FEES (BILL_NO,PAYMENT_DATE,MONTH_PAID,STUDENT_ID,DUE) values (5,to_timestamp('09-SEP-15 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),10,1,100);
Insert into FEES (BILL_NO,PAYMENT_DATE,MONTH_PAID,STUDENT_ID,DUE) values (6,to_timestamp('04-APR-15 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),4,7,400);

---------------------------------------------------
--   END DATA FOR TABLE FEES
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE GENSUBJECT
--   FILTER = none used
---------------------------------------------------
REM INSERTING into GENSUBJECT
Insert into GENSUBJECT (SUBJECT_ID,SUBJECT_NAME) values (1,'GENERAL SCIENCE');
Insert into GENSUBJECT (SUBJECT_ID,SUBJECT_NAME) values (2,'MATHEMATICS');
Insert into GENSUBJECT (SUBJECT_ID,SUBJECT_NAME) values (3,'ENGLISH');
Insert into GENSUBJECT (SUBJECT_ID,SUBJECT_NAME) values (4,'BANGLA');
Insert into GENSUBJECT (SUBJECT_ID,SUBJECT_NAME) values (5,'SOCIOLOGY');
Insert into GENSUBJECT (SUBJECT_ID,SUBJECT_NAME) values (6,'PHYSICAL EDUCATION');

---------------------------------------------------
--   END DATA FOR TABLE GENSUBJECT
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE GRADES
--   FILTER = none used
---------------------------------------------------
REM INSERTING into GRADES
Insert into GRADES (GRADE_ID,GRADE_POINT,MERIT_POSITION,STUDENT_ID,CLASS_ID) values (1,3.98,1,1,6);

---------------------------------------------------
--   END DATA FOR TABLE GRADES
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE SECTION
--   FILTER = none used
---------------------------------------------------
REM INSERTING into SECTION
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (1,6,'A',102,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (2,7,'B',105,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (2,6,'B',103,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (1,7,'A',104,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (1,8,'A',109,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (2,8,'B',115,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (1,9,'A',110,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (2,9,'B',111,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (1,10,'A',112,null);
Insert into SECTION (SECTION_ID,CLASS_ID,SECTION_NAME,ROOM_NO,NO_OF_STUDENTS) values (2,10,'B',113,null);

---------------------------------------------------
--   END DATA FOR TABLE SECTION
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE STUDENTS
--   FILTER = none used
---------------------------------------------------
REM INSERTING into STUDENTS
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (1,'SAKIBUR','RAHMAN',to_timestamp('07-JUL-99 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,6,1);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (2,'SHAHED','KHAN',to_timestamp('02-JUL-95 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,6,2);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (3,'PALLAB','MANDAL',to_timestamp('08-AUG-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,6,3);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (4,'SHUVO','KARMAKAR',to_timestamp('08-OCT-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,6,4);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (5,'ALI','HOSSAIN',to_timestamp('09-SEP-97 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,6,5);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (6,'BISHWAJIT','SAHA',to_timestamp('02-APR-97 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,6,1);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (7,'ABUL','FAZAL',to_timestamp('09-SEP-97 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,6,2);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (8,'KOLIM','HOSSAIN',to_timestamp('09-JUN-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,6,3);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (9,'PROTTOY','SAHA',to_timestamp('08-JUL-00 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,6,4);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (10,'ALTAF','HOSSAIN',to_timestamp('04-APR-95 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,7,1);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (11,'KAJOL','SHIKDAR',to_timestamp('08-AUG-94 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,7,2);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (12,'HALIM','SHEIKH',to_timestamp('05-MAY-01 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,7,3);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (13,'KAMOL','SEN',to_timestamp('08-AUG-98 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,7,4);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (14,'KADER','KHAN',to_timestamp('08-APR-98 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,7,5);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (15,'SANJAY','PAUL',to_timestamp('08-MAY-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,7,1);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (16,'MRINAL','GHOSH',to_timestamp('06-APR-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,7,2);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (17,'ABDUL','HAI',to_timestamp('05-MAY-95 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,7,3);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (18,'RAKIBUL','ISLAM',to_timestamp('06-JUN-95 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,7,4);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (19,'RUBEL','KHALIFA',to_timestamp('06-APR-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,7,5);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (20,'MAHBUB','ALAM',to_timestamp('06-JUN-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,8,1);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (21,'AHMED','WASIF',to_timestamp('04-APR-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,8,2);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (22,'FAHIM','ISLAM',to_timestamp('06-JUN-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,8,3);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (23,'PRONOB','PAUL',to_timestamp('04-JUN-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,8,4);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (24,'MASUDUR','RAHMAN',to_timestamp('04-APR-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',1,8,5);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (25,'RAJAT','CHAKRABARTY',to_timestamp('04-JUN-93 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,8,1);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (26,'MILTON','MARMA',to_timestamp('03-MAR-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,8,2);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (27,'ARNOB','PAUL',to_timestamp('05-MAY-93 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,8,3);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (28,'ALIM','DAR',to_timestamp('08-JUL-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,8,4);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (29,'HASNUR','RAHMAN',to_timestamp('06-SEP-96 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,8,5);
Insert into STUDENTS (STUDENT_ID,FIRST_NAME,LAST_NAME,BIRTH_DATE,GENDER,SECTION_ID,CLASS_ID,ROLL) values (30,'KALAM','MOLLA',to_timestamp('09-SEP-99 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE',2,6,5);

---------------------------------------------------
--   END DATA FOR TABLE STUDENTS
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE SUBJECT
--   FILTER = none used
---------------------------------------------------
REM INSERTING into SUBJECT
Insert into SUBJECT (SUBJECT_ID,SECTION_ID,CLASS_ID,SUBJECT_NAME,CLASS_TIME,TEACHER_ID) values (3,1,6,'ENGLISH','12:00',4);
Insert into SUBJECT (SUBJECT_ID,SECTION_ID,CLASS_ID,SUBJECT_NAME,CLASS_TIME,TEACHER_ID) values (1,1,6,'GENERAL SCIENCE','10:00',3);
Insert into SUBJECT (SUBJECT_ID,SECTION_ID,CLASS_ID,SUBJECT_NAME,CLASS_TIME,TEACHER_ID) values (4,1,6,'BANGLA','11:00',1);
Insert into SUBJECT (SUBJECT_ID,SECTION_ID,CLASS_ID,SUBJECT_NAME,CLASS_TIME,TEACHER_ID) values (6,2,6,'PHYSICAL EDUCATION','11:00',2);
Insert into SUBJECT (SUBJECT_ID,SECTION_ID,CLASS_ID,SUBJECT_NAME,CLASS_TIME,TEACHER_ID) values (4,2,6,'BANGLA','10:00',5);
Insert into SUBJECT (SUBJECT_ID,SECTION_ID,CLASS_ID,SUBJECT_NAME,CLASS_TIME,TEACHER_ID) values (1,2,6,'GENERAL SCIENCE','12:00',3);
Insert into SUBJECT (SUBJECT_ID,SECTION_ID,CLASS_ID,SUBJECT_NAME,CLASS_TIME,TEACHER_ID) values (4,1,7,'BANGLA','10:00',1);

---------------------------------------------------
--   END DATA FOR TABLE SUBJECT
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE TEACHERS
--   FILTER = none used
---------------------------------------------------
REM INSERTING into TEACHERS
Insert into TEACHERS (TEACHER_ID,FIRST_NAME,LAST_NAME,JOIN_DATE,GENDER,POSITION,POS_VAL) values (4,'ALTAF','CHOWDHURY',to_timestamp('02-AUG-14 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE','TEACHER',4);
Insert into TEACHERS (TEACHER_ID,FIRST_NAME,LAST_NAME,JOIN_DATE,GENDER,POSITION,POS_VAL) values (2,'KHALID','ISLAM',to_timestamp('07-JUL-14 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE','ASSISTANT HEADMASTER',0);
Insert into TEACHERS (TEACHER_ID,FIRST_NAME,LAST_NAME,JOIN_DATE,GENDER,POSITION,POS_VAL) values (3,'MITHUN','RAI',to_timestamp('08-JUL-13 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE','JUNIOR TEACHER',5);
Insert into TEACHERS (TEACHER_ID,FIRST_NAME,LAST_NAME,JOIN_DATE,GENDER,POSITION,POS_VAL) values (5,'HABIBUR','RAHMAN',to_timestamp('07-JUL-14 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE','HEADMASTER',1);
Insert into TEACHERS (TEACHER_ID,FIRST_NAME,LAST_NAME,JOIN_DATE,GENDER,POSITION,POS_VAL) values (1,'LATIF','HASAN',to_timestamp('07-SEP-15 12.00.00.000000000 AM','DD-MON-RR HH.MI.SS.FF AM'),'MALE','TEACHER',4);

---------------------------------------------------
--   END DATA FOR TABLE TEACHERS
---------------------------------------------------


---------------------------------------------------
--   DATA FOR TABLE USERS
--   FILTER = none used
---------------------------------------------------
REM INSERTING into USERS
Insert into USERS (USERNAME,PASSWORD) values ('S','S');
Insert into USERS (USERNAME,PASSWORD) values ('FIRST','FIRST');
Insert into USERS (USERNAME,PASSWORD) values ('SECOND','SECOND');
Insert into USERS (USERNAME,PASSWORD) values ('ADMIN','ADMIN');
Insert into USERS (USERNAME,PASSWORD) values ('A','A');

---------------------------------------------------
--   END DATA FOR TABLE USERS
---------------------------------------------------

--------------------------------------------------------
--  Constraints for Table STUDENTS
--------------------------------------------------------

  ALTER TABLE "STUDENTS" ADD CONSTRAINT "STD_PK" PRIMARY KEY ("STUDENT_ID") ENABLE;
 
  ALTER TABLE "STUDENTS" ADD CONSTRAINT "STD_UNQ" UNIQUE ("SECTION_ID", "CLASS_ID", "ROLL") ENABLE;
 
  ALTER TABLE "STUDENTS" MODIFY ("FIRST_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "STUDENTS" MODIFY ("LAST_NAME" NOT NULL ENABLE);
 
  ALTER TABLE "STUDENTS" MODIFY ("SECTION_ID" NOT NULL ENABLE);
 
  ALTER TABLE "STUDENTS" MODIFY ("CLASS_ID" NOT NULL ENABLE);
 
  ALTER TABLE "STUDENTS" MODIFY ("ROLL" NOT NULL ENABLE);
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

  ALTER TABLE "SUBJECT" ADD CONSTRAINT "SUB_UNQ" UNIQUE ("SECTION_ID", "CLASS_ID", "CLASS_TIME") ENABLE;
 
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

  ALTER TABLE "GRADES" ADD CONSTRAINT "STUD_UN" UNIQUE ("STUDENT_ID") ENABLE;
 
  ALTER TABLE "GRADES" MODIFY ("GRADE_ID" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" MODIFY ("GRADE_POINT" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" MODIFY ("MERIT_POSITION" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" MODIFY ("STUDENT_ID" NOT NULL ENABLE);
 
  ALTER TABLE "GRADES" ADD PRIMARY KEY ("GRADE_ID") ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("GRADE_ID" IS NOT NULL) ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("GRADE_POINT" IS NOT NULL) ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("MERIT_POSITION" IS NOT NULL) ENABLE;
 
  ALTER TABLE "GRADES" ADD CHECK ("STUDENT_ID" IS NOT NULL) ENABLE;
 
  ALTER TABLE "GRADES" MODIFY ("CLASS_ID" NOT NULL ENABLE);
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
--  DDL for Index STUD_UN
--------------------------------------------------------

  CREATE UNIQUE INDEX "STUD_UN" ON "GRADES" ("STUDENT_ID") 
  ;
--------------------------------------------------------
--  DDL for Index STD_UNQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "STD_UNQ" ON "STUDENTS" ("SECTION_ID", "CLASS_ID", "ROLL") 
  ;
--------------------------------------------------------
--  DDL for Index SUB_UNQ
--------------------------------------------------------

  CREATE UNIQUE INDEX "SUB_UNQ" ON "SUBJECT" ("SECTION_ID", "CLASS_ID", "CLASS_TIME") 
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

