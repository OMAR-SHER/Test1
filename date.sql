SELECT CURRENT_TIMESTAMP AS Result1;
SELECT GETUTCDATE() as Result2;
SELECT GETDATE() as Result3;
select sysdatetime() as Result4;
select sysutcdatetime() as Result5;
select sysdatetimeoffset() as Result6;
use  indexing;
select* from earthquake1;
select day(occurred_on) as OmarSher from earthquake1 ;
select month(occurred_on) as OmarSher from earthquake1 ;
select year(occurred_on) as OmarSher from earthquake1 ;
SELECT DATEDIFF(month,  convert(varchar(10),getdate(),1), '2011/08/25') AS DateDiff;
SELECT DATEDIFF(month, '1969-12-31 23:59:59.9999999' ,'1969-01-01 00:00:00.0000000' ) AS DateDiff;
SELECT DATEDIFF(year, '1969-12-31 23:59:59.9999999' ,'1969-01-01 00:00:00.0000000' ) AS DateDiff;
SELECT DATEDIFF(day, '1969-10-31 23:59:59.9999999' ,'1969-11-01 00:00:00.0000000' ) AS DateDiff;